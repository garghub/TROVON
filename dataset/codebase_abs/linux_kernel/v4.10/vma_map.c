void F_1 ( struct V_1 * V_2 )
{
while ( V_2 ) {
struct V_1 * V_3 = V_2 -> V_3 ;
F_2 ( V_2 ) ;
V_2 = V_3 ;
}
}
unsigned int
F_3 ( struct V_1 * V_2 , unsigned int V_4 ,
const struct V_5 * V_6 , int * V_7 )
{
T_1 V_8 = 0x10000000 + V_4 ;
T_1 V_9 ;
for (; V_2 ; V_2 = V_2 -> V_3 ) {
if ( V_4 < V_2 -> V_4 || V_4 >= V_2 -> V_4 + V_2 -> V_10 )
continue;
if ( V_2 -> V_11 ) {
V_9 = * ( T_1 * ) ( V_6 -> V_12 + V_2 -> V_11 ) ;
if ( V_9 != V_2 -> V_13 )
continue;
* V_7 = V_9 ;
}
V_8 = V_4 - V_2 -> V_4 + V_2 -> V_8 ;
break;
}
return V_8 ;
}
static struct V_1 *
F_4 ( struct V_1 * V_2 , unsigned int V_4 ,
unsigned int V_10 , unsigned int V_8 , unsigned int V_11 ,
unsigned int V_13 )
{
struct V_1 * V_14 =
F_5 ( sizeof( struct V_1 ) , V_15 ) ;
if ( ! V_14 ) {
F_6 ( V_16 L_1 ,
V_17 , __LINE__ ) ;
F_1 ( V_2 ) ;
return NULL ;
}
V_14 -> V_3 = V_2 ;
V_14 -> V_4 = V_4 ;
V_14 -> V_10 = V_10 ;
V_14 -> V_8 = V_8 ;
V_14 -> V_11 = V_11 ;
V_14 -> V_13 = V_13 ;
return V_14 ;
}
struct V_1 * F_7 ( const struct V_5 * V_6 ,
unsigned long V_18 )
{
static const unsigned char V_19 [ V_20 ] = {
[ V_21 ] = V_22 ,
[ V_23 ] = V_24 ,
[ V_25 ] = V_26 ,
[ V_27 ] = V_28 ,
[ V_29 ] = V_30 ,
[ V_31 ] = V_32 ,
[ V_33 ] = V_34 ,
[ V_35 ] = V_36
} ;
int V_7 ;
struct V_1 * V_2 = NULL ;
void T_2 * V_37 = ( void T_2 * ) V_18 ;
struct V_38 V_39 ;
unsigned int V_40 = - 1 ;
T_3 T_2 * V_41 ;
T_4 T_2 * V_42 ;
T_5 V_43 ;
T_3 V_44 ;
T_4 V_45 , V_46 ;
T_6 V_47 ;
int V_48 , V_49 ;
char V_50 [ 32 ] ;
unsigned int V_51 = 0 ;
unsigned int V_52 = 0 ;
unsigned int V_53 = 0 ;
unsigned int V_54 = 0 ;
struct V_38 T_2 * V_55 ;
unsigned int V_56 ;
if ( F_8 ( & V_43 , V_37 , sizeof ( V_43 ) ) )
goto V_57;
if ( memcmp ( V_43 . V_58 , V_19 , V_20 ) != 0 ) {
F_6 ( V_16 L_2
L_3 ,
V_17 , __LINE__ ) ;
goto V_57;
}
if ( V_43 . V_59 != V_60 ) {
F_6 ( V_16 L_2
L_4 ,
V_17 , __LINE__ ) ;
goto V_57;
}
if ( V_43 . V_61 != V_62 ) {
F_6 ( V_16 L_2
L_5 ,
V_17 , __LINE__ ) ;
goto V_57;
}
V_41 = V_37 + V_43 . V_63 ;
V_42 = V_37 + V_43 . V_64 ;
for ( V_48 = 0 ; V_48 < V_43 . V_65 ; V_48 ++ ) {
if ( F_8 ( & V_44 , V_41 + V_48 , sizeof( V_44 ) ) )
goto V_57;
if ( V_44 . V_66 != V_67 )
continue;
if ( V_44 . V_68 & ( 1 << 27 ) )
continue;
V_2 = F_4 ( V_2 , V_44 . V_69 , V_44 . V_70 ,
V_44 . V_71 , 0 , 0 ) ;
if ( ! V_2 )
goto V_57;
}
F_9 ( L_6 ) ;
for ( V_48 = 0 ; V_48 < V_43 . V_72 ; V_48 ++ ) {
if ( F_8 ( & V_45 , V_42 + V_48 , sizeof( V_45 ) ) )
goto V_57;
if ( V_45 . V_73 != V_74 )
continue;
if ( V_45 . V_75 != sizeof ( V_47 ) )
continue;
if ( F_8 ( & V_46 ,
V_42 + V_45 . V_76 ,
sizeof( V_45 ) ) )
goto V_57;
if ( V_46 . V_73 != V_77 )
goto V_57;
for ( V_49 = 0 ; V_49 < V_45 . V_78 / sizeof ( V_47 ) ; V_49 ++ ) {
if ( F_8 ( & V_47 , V_37 +
V_45 . V_79 +
V_49 * sizeof ( V_47 ) ,
sizeof ( V_47 ) ) )
goto V_57;
if ( F_8 ( V_50 ,
V_37 + V_46 . V_79 +
V_47 . V_80 ,
20 ) )
goto V_57;
if ( memcmp ( V_50 , L_7 , 12 ) == 0 )
V_51 = V_47 . V_81 ;
if ( memcmp ( V_50 , L_8 , 16 ) == 0 )
V_52 = V_47 . V_81 ;
if ( memcmp ( V_50 , L_9 , 16 ) == 0 )
V_53 = V_47 . V_81 ;
if ( memcmp ( V_50 , L_10 , 20 ) == 0 )
V_54 = V_47 . V_81 ;
}
}
if ( V_51 == 0 || V_52 == 0
|| V_53 == 0 || V_54 == 0 ) {
F_9 ( L_11 ) ;
goto V_82;
} else {
F_9 ( L_12 ) ;
}
V_40 = F_3 ( V_2 , V_51 ,
V_6 , & V_7 ) ;
if ( V_40 > 0x10000000 ) {
F_6 ( V_16 L_2
L_13 ,
V_17 , __LINE__ ) ;
goto V_57;
}
V_55 = V_37 + V_40 ;
V_56 = ( V_53 -
V_51 ) / sizeof ( V_39 ) ;
for ( V_48 = 0 ; V_48 < V_56 ; V_48 ++ ) {
if ( F_8 ( & V_39 , V_55 + V_48 , sizeof ( V_39 ) ) )
goto V_57;
V_2 = F_4 ( V_2 , V_39 . V_4 , V_39 . V_10 , V_39 . V_8 ,
V_52 + ( V_39 . V_83 - 1 ) * 4 , V_48 + 1 ) ;
if ( ! V_2 )
goto V_57;
}
goto V_82;
V_57:
V_2 = NULL ;
V_82:
return V_2 ;
}
