static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 != - 1 )
F_2 ( V_2 -> V_3 ) ;
V_2 -> V_3 = - 1 ;
V_2 -> V_4 = 0 ;
V_2 -> V_5 = 0 ;
V_2 -> V_6 = false ;
}
static bool F_3 ( struct V_1 * V_7 , const T_1 * V_8 ,
unsigned char V_9 , bool V_10 )
{
int V_11 ;
struct V_12 * V_2 ;
struct V_13 V_14 ;
F_1 ( V_7 ) ;
V_7 -> V_10 = V_10 ;
V_7 -> V_3 = F_4 ( L_1 , V_15 ) ;
if ( V_7 -> V_3 == - 1 ) {
F_5 ( V_7 , L_2 ) ;
goto V_16;
}
memcpy ( & V_7 -> V_8 , V_8 , sizeof( * V_8 ) ) ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_7 -> V_6 = true ;
memcpy ( & V_14 . V_17 , & V_7 -> V_8 , sizeof( V_7 -> V_8 ) ) ;
V_11 = F_6 ( V_7 -> V_3 , V_18 , & V_14 ) ;
if ( V_11 ) {
F_5 ( V_7 , L_3 , V_11 ) ;
goto V_16;
}
V_2 = & V_14 . V_19 ;
F_7 ( V_7 , L_4 , V_2 -> V_20 ) ;
F_7 ( V_7 , L_5 , V_2 -> V_21 ) ;
if ( ( V_9 > 0 ) &&
( V_2 -> V_21 != V_9 ) ) {
F_5 ( V_7 , L_6 ) ;
goto V_16;
}
V_7 -> V_4 = V_2 -> V_20 ;
V_7 -> V_5 = V_2 -> V_21 ;
return true ;
V_16:
F_1 ( V_7 ) ;
return false ;
}
static T_2 F_8 ( struct V_1 * V_7 , unsigned char * V_22 ,
T_2 V_23 , unsigned long V_24 )
{
T_2 V_25 ;
F_7 ( V_7 , L_7 , V_23 ) ;
V_25 = F_9 ( V_7 -> V_3 , V_22 , V_23 ) ;
if ( V_25 < 0 ) {
F_5 ( V_7 , L_8 ,
V_25 , strerror ( V_26 ) ) ;
F_1 ( V_7 ) ;
} else {
F_7 ( V_7 , L_9 , V_25 ) ;
}
return V_25 ;
}
static T_2 F_10 ( struct V_1 * V_7 , const unsigned char * V_22 ,
T_2 V_23 , unsigned long V_24 )
{
struct V_27 V_28 ;
T_2 V_29 ;
T_2 V_25 ;
T_3 V_30 ;
V_28 . V_31 = V_24 / 1000 ;
V_28 . V_32 = ( V_24 % 1000 ) * 1000000 ;
F_7 ( V_7 , L_10 , V_23 ) ;
V_29 = F_11 ( V_7 -> V_3 , V_22 , V_23 ) ;
if ( V_29 < 0 ) {
V_25 = - V_26 ;
F_5 ( V_7 , L_11 ,
V_29 , strerror ( V_26 ) ) ;
goto V_33;
}
F_12 ( & V_30 ) ;
F_13 ( V_7 -> V_3 , & V_30 ) ;
V_25 = F_14 ( V_7 -> V_3 + 1 , & V_30 , NULL , NULL , & V_28 ) ;
if ( V_25 > 0 && F_15 ( V_7 -> V_3 , & V_30 ) ) {
F_7 ( V_7 , L_12 ) ;
} else if ( V_25 == 0 ) {
F_5 ( V_7 , L_13 ) ;
goto V_33;
} else {
F_5 ( V_7 , L_14 , V_25 ) ;
goto V_33;
}
V_25 = V_29 ;
V_33:
if ( V_25 < 0 )
F_1 ( V_7 ) ;
return V_25 ;
}
static bool F_16 ( struct V_34 * V_35 ,
unsigned long V_36 , bool V_10 )
{
V_35 -> V_36 = ( V_36 ) ? V_36 : 20000 ;
V_35 -> V_6 = F_3 ( & V_35 -> V_37 , & V_38 , 0 , V_10 ) ;
return V_35 -> V_6 ;
}
static void F_17 ( struct V_34 * V_35 )
{
F_1 ( & V_35 -> V_37 ) ;
V_35 -> V_6 = false ;
}
static T_4 F_18 ( const struct V_39 * V_40 )
{
T_4 V_41 = V_42 ;
struct V_43 * V_44 ;
T_5 V_45 ;
T_4 V_46 ;
T_4 V_23 ;
T_4 V_47 ;
V_44 = (struct V_43 * ) V_40 -> V_14 ;
V_45 = V_40 -> V_48 . V_49 - sizeof( T_4 ) ;
V_46 = V_45 -
sizeof( V_44 -> V_50 ) -
sizeof( V_44 -> V_51 ) ;
if ( V_44 -> V_51 != V_46 / sizeof( struct V_52 ) ) {
V_41 = V_53 ;
goto V_33;
}
for ( V_47 = 0 ; V_47 < V_44 -> V_51 ; V_47 ++ ) {
V_23 = V_44 -> V_54 [ V_47 ] . V_55 . V_49 ;
if ( V_23 > V_56 ) {
V_41 = V_53 ;
goto V_33;
}
V_23 = V_44 -> V_54 [ V_47 ] . V_57 . V_49 ;
if ( V_44 -> V_54 [ V_47 ] . V_57 . string [ V_23 ] != '\0' ||
V_23 != strlen ( V_44 -> V_54 [ V_47 ] . V_57 . string ) ) {
V_41 = V_53 ;
goto V_33;
}
}
V_33:
return V_41 ;
}
static T_4 F_19 ( T_4 V_58 ,
const struct V_59 * V_60 ,
T_4 V_61 )
{
if ( V_61 < sizeof( struct V_39 ) ) {
return V_53 ;
} else if ( V_61 != ( V_60 -> V_49 +
sizeof( struct V_59 ) ) ) {
return V_53 ;
} else if ( V_60 -> V_58 != V_58 ) {
return V_53 ;
} else if ( V_60 -> V_62 != 0 ) {
return V_53 ;
} else if ( V_60 -> V_57 . V_63 != V_64 ||
V_60 -> V_57 . V_65 < V_66 ) {
return V_53 ;
}
return V_42 ;
}
static T_4 F_20 ( struct V_34 * V_35 ,
const unsigned char * V_58 , T_2 V_67 ,
T_6 * * V_68 , T_4 V_69 ,
unsigned int V_70 )
{
T_4 V_71 ;
T_4 V_72 ;
T_2 V_29 ;
T_4 V_41 ;
struct V_39 * V_73 ;
V_71 = V_35 -> V_37 . V_4 ;
* V_68 = ( T_6 * ) malloc ( sizeof( T_6 ) * V_71 ) ;
if ( * V_68 == NULL )
return V_74 ;
memset ( * V_68 , 0 , V_71 ) ;
V_73 = (struct V_39 * ) * V_68 ;
V_29 = F_10 ( & V_35 -> V_37 ,
V_58 , V_67 , V_35 -> V_36 ) ;
if ( V_29 != V_67 )
return V_53 ;
V_72 = F_8 ( & V_35 -> V_37 , * V_68 , V_71 , 2000 ) ;
if ( V_72 <= 0 )
return V_75 ;
V_41 = V_73 -> V_41 ;
if ( V_41 != V_42 )
return V_41 ;
V_41 = F_19 ( V_69 ,
& V_73 -> V_48 , V_72 ) ;
if ( V_41 != V_42 )
return V_41 ;
if ( V_70 && V_70 != V_72 )
return V_53 ;
return V_42 ;
}
static T_4 F_21 ( struct V_34 * V_76 ,
struct V_43 * V_54 )
{
struct V_39 * V_77 = NULL ;
T_4 V_41 ;
V_41 = F_20 ( V_76 ,
( const unsigned char * ) & V_78 ,
sizeof( V_78 ) ,
( T_6 * * ) & V_77 ,
V_79 , 0 ) ;
if ( V_41 != V_42 )
goto V_33;
V_41 = F_18 ( V_77 ) ;
if ( V_41 != V_42 )
goto V_33;
memcpy ( V_54 , V_77 -> V_14 , sizeof( struct V_43 ) ) ;
V_33:
if ( V_77 != NULL )
free ( V_77 ) ;
return V_41 ;
}
int main ( int V_80 , char * * V_81 )
{
struct V_43 V_82 ;
struct V_34 V_35 ;
unsigned int V_47 ;
T_4 V_41 ;
int V_83 ;
bool V_10 ;
V_10 = ( V_80 > 1 && strcmp ( V_81 [ 1 ] , L_15 ) == 0 ) ;
if ( ! F_16 ( & V_35 , 5000 , V_10 ) ) {
V_83 = 1 ;
goto V_33;
}
V_41 = F_21 ( & V_35 , & V_82 ) ;
F_17 ( & V_35 ) ;
switch ( V_41 ) {
case V_75 :
printf ( L_16 ) ;
V_83 = 0 ;
break;
case V_42 :
printf ( L_17 ) ;
for ( V_47 = 0 ; V_47 < V_82 . V_51 ; V_47 ++ ) {
printf ( L_18 , V_82 . V_54 [ V_47 ] . V_55 . string ,
V_82 . V_54 [ V_47 ] . V_57 . string ) ;
}
V_83 = 0 ;
break;
default:
printf ( L_19 ) ;
V_83 = 1 ;
break;
}
V_33:
return V_83 ;
}
