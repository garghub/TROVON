static int F_1 ( unsigned long V_1 , unsigned short * V_2 , unsigned char * V_3 ,
unsigned char * V_4 )
{
int V_5 ;
int V_6 = 0 ;
V_5 = 0 ;
while ( V_7 [ V_5 ] . V_1 > 0 && V_1 > V_7 [ V_5 ] . V_1 )
V_5 ++ ;
if ( V_7 [ V_5 ] . V_1 > 0 ) {
if ( V_2 )
* V_2 = V_7 [ V_5 ] . V_2 ;
if ( V_3 )
* V_3 = V_7 [ V_5 ] . V_3 ;
if ( V_4 )
* V_4 = V_7 [ V_5 ] . V_4 ;
V_6 = 1 ;
}
return V_6 ;
}
static int F_2 ( struct V_8 * V_9 )
{
int V_10 , V_5 , V_11 ;
T_1 V_12 ;
T_2 V_13 ;
T_3 * V_14 ;
V_11 = - 1 ;
V_14 = F_3 ( V_15 , V_16 ) ;
if ( ! V_14 )
goto V_17;
for ( V_5 = 0 , V_13 = 0 ; V_5 < 4 ; V_5 ++ , V_13 += V_9 -> V_18 ) {
if ( ! V_9 -> V_19 ( V_9 , V_13 ) ) {
V_10 = V_9 -> V_20 ( V_9 , V_13 , V_15 , & V_12 ,
V_14 ) ;
if ( V_10 < 0 || V_12 != V_15 ) {
F_4 ( V_21
L_1 ) ;
} else if ( ! memcmp ( V_14 , V_22 ,
sizeof( V_22 ) ) ) {
V_11 = ( int ) ( V_13 >> V_23 ) ;
} else {
F_5 ( L_2
L_3 , V_9 -> V_24 ,
V_9 -> V_25 ) ;
}
break;
}
}
F_6 ( V_14 ) ;
V_17:
return V_11 ;
}
static int F_7 ( struct V_8 * V_9 , T_3 * V_14 ,
int V_26 )
{
int V_10 ;
T_1 V_12 ;
T_2 V_13 = ( T_2 ) V_26 << V_23 ;
V_10 = V_9 -> V_20 ( V_9 , V_13 , V_15 , & V_12 , V_14 ) ;
if ( V_10 < 0 || V_12 != V_15 )
return - 1 ;
return 0 ;
}
static int F_8 ( struct V_8 * V_9 , T_2 V_27 , T_3 * V_28 )
{
struct V_29 V_30 ;
int V_10 ;
V_30 . V_31 = V_32 ;
V_30 . V_33 = 0 ;
V_30 . V_34 = V_35 ;
V_30 . V_36 = V_28 ;
V_30 . V_37 = NULL ;
V_10 = V_9 -> V_38 ( V_9 , V_27 , & V_30 ) ;
if ( V_10 < 0 || V_30 . V_39 != V_35 )
return - 1 ;
return 0 ;
}
static int F_9 ( int V_40 , int V_1 )
{
int V_5 ;
int V_41 ;
V_41 = 1 ;
for ( V_5 = 0 ; V_5 < V_1 ; V_5 ++ ) {
V_41 += ( V_40 >> V_5 ) ;
V_41 &= 1 ;
}
return V_41 ;
}
static int F_10 ( T_3 * V_42 )
{
int V_43 , V_41 ;
int V_13 [ 2 ] = { 6 , 11 } ;
int V_44 ;
int V_45 = 0 ;
for ( V_44 = 0 ; V_44 < F_11 ( V_13 ) ; V_44 ++ ) {
V_43 = ( ( int ) V_42 [ V_13 [ V_44 ] ] << 8 ) |
V_42 [ V_13 [ V_44 ] + 1 ] ;
if ( ( V_43 & ~ 0x7FF ) == 0x1000 ) {
V_41 = V_43 & 0x01 ;
V_43 &= 0x7FF ;
V_43 >>= 1 ;
if ( F_9 ( V_43 , 10 ) != V_41 ) {
F_5 ( L_4
L_5 , V_44 + 1 ,
V_43 ) ;
} else {
V_45 = 1 ;
break;
}
}
}
if ( ! V_45 )
V_43 = - 2 ;
F_5 ( L_6 ,
V_43 ) ;
return V_43 ;
}
static int F_12 ( struct V_46 * V_47 )
{
unsigned long V_13 ;
T_3 V_42 [ V_35 ] ;
int V_10 , V_43 , V_48 ;
struct V_8 * V_9 = V_47 -> V_49 . V_9 ;
F_5 ( L_7 ,
V_47 -> V_50 ,
( unsigned long ) V_47 -> V_50 * V_47 -> V_51 / 1024 ) ;
for ( V_48 = V_47 -> V_52 + 1 ; V_48 < V_47 -> V_50 ;
V_48 ++ ) {
V_13 = ( unsigned long ) V_48 * V_47 -> V_51 ;
if ( V_9 -> V_19 ( V_9 , V_13 ) )
continue;
V_10 = F_8 ( V_9 , V_13 , V_42 ) ;
if ( V_10 < 0 ) {
F_5 ( L_8 ,
V_13 ) ;
return - 1 ;
}
V_43 = F_10 ( V_42 ) ;
if ( V_43 >= 0 &&
V_43 < V_53 ) {
int V_54 ;
V_54 = V_48 / V_55 ;
V_43 += V_54 * V_53 ;
V_47 -> V_56 [ V_43 ] =
( unsigned short ) V_48 ;
F_5 ( L_9
L_10 ,
V_48 , V_43 , V_54 ) ;
}
}
return 0 ;
}
static void F_13 ( struct V_57 * V_58 , struct V_8 * V_9 )
{
struct V_46 * V_47 ;
int V_11 ;
if ( V_9 -> type != V_59 || V_9 -> V_60 != V_35 ||
V_9 -> V_1 > V_61 )
return;
V_11 = F_2 ( V_9 ) ;
if ( V_11 == - 1 )
return;
V_47 = F_14 ( sizeof( struct V_46 ) , V_16 ) ;
if ( ! V_47 )
return;
V_47 -> V_49 . V_9 = V_9 ;
V_47 -> V_49 . V_62 = - 1 ;
V_47 -> V_49 . V_58 = V_58 ;
V_47 -> V_49 . V_63 = 1 ;
V_47 -> V_52 = V_11 / ( V_9 -> V_18 >> V_23 ) ;
V_47 -> V_51 = V_9 -> V_18 ;
V_47 -> V_50 = ( V_64 ) V_9 -> V_1 / V_9 -> V_18 ;
F_5 ( L_11 ,
V_47 -> V_52 , V_47 -> V_51 , V_47 -> V_50 ,
F_15 ( V_47 -> V_50 , V_55 ) ) ;
V_47 -> V_65 = 16 ;
V_47 -> V_66 = 32 ;
F_1 ( V_9 -> V_1 , NULL , & V_47 -> V_65 , & V_47 -> V_66 ) ;
V_47 -> V_67 = ( unsigned short ) ( ( ( V_64 ) V_9 -> V_1 >> V_23 ) /
( ( long ) V_47 -> V_66 * ( long ) V_47 -> V_65 ) ) ;
F_5 ( L_12 ,
V_47 -> V_67 , V_47 -> V_65 , V_47 -> V_66 ,
( long ) V_47 -> V_67 * ( long ) V_47 -> V_65 *
( long ) V_47 -> V_66 ) ;
V_47 -> V_49 . V_1 = ( long ) V_47 -> V_65 * ( long ) V_47 -> V_67 *
( long ) V_47 -> V_66 ;
V_47 -> V_56 = F_3 ( sizeof( V_47 -> V_56 [ 0 ] ) *
V_47 -> V_50 , V_16 ) ;
if ( ! V_47 -> V_56 )
goto V_68;
memset ( V_47 -> V_56 , 0xff , sizeof( V_47 -> V_56 [ 0 ] ) *
V_47 -> V_50 ) ;
if ( F_12 ( V_47 ) < 0 )
goto V_68;
if ( F_16 ( & V_47 -> V_49 ) )
goto V_68;
F_4 ( V_69 L_13 ,
V_47 -> V_49 . V_62 + 'a' , V_9 -> V_25 , V_9 -> V_24 ) ;
return;
V_68:
F_6 ( V_47 -> V_56 ) ;
F_6 ( V_47 ) ;
}
static void F_17 ( struct V_70 * V_71 )
{
struct V_46 * V_47 = (struct V_46 * ) V_71 ;
F_5 ( L_14 , V_71 -> V_62 ) ;
F_18 ( V_71 ) ;
F_6 ( V_47 -> V_56 ) ;
}
static int F_19 ( struct V_70 * V_71 ,
unsigned long V_72 , char * V_28 )
{
struct V_46 * V_47 = (struct V_46 * ) V_71 ;
int V_73 , V_13 , V_43 ;
V_73 = V_47 -> V_51 >> V_23 ;
V_13 = ( int ) ( V_72 % V_73 ) ;
V_43 = ( int ) ( V_72 / V_73 ) ;
F_5 ( L_15
L_16 , V_72 , V_73 , V_13 ,
V_43 ) ;
if ( V_43 >= V_47 -> V_50 )
F_20 () ;
V_43 = V_47 -> V_56 [ V_43 ] ;
F_5 ( L_17 ,
V_43 ) ;
if ( V_43 < 0xffff ) {
unsigned long V_26 ;
V_26 = ( unsigned long ) V_43 * V_73 +
V_13 ;
F_5 ( L_18 ,
V_26 ) ;
if ( F_7 ( V_47 -> V_49 . V_9 , V_28 , V_26 ) < 0 )
return - V_74 ;
} else {
memset ( V_28 , 0xff , V_15 ) ;
}
return 0 ;
}
static int F_21 ( struct V_70 * V_71 , struct V_75 * V_76 )
{
struct V_46 * V_47 = (struct V_46 * ) V_71 ;
F_5 ( L_19 ,
V_47 -> V_67 , V_47 -> V_65 , V_47 -> V_66 ) ;
V_76 -> V_65 = V_47 -> V_65 ;
V_76 -> V_66 = V_47 -> V_66 ;
V_76 -> V_67 = V_47 -> V_67 ;
return 0 ;
}
static int T_4 F_22 ( void )
{
F_4 ( V_69 L_20 ) ;
return F_23 ( & V_77 ) ;
}
static void T_5 F_24 ( void )
{
F_25 ( & V_77 ) ;
}
