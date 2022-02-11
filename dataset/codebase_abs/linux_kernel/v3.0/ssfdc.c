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
F_5 ( V_24 ,
L_2
L_3 , V_9 -> V_25 ,
V_9 -> V_26 ) ;
}
break;
}
}
F_6 ( V_14 ) ;
V_17:
return V_11 ;
}
static int F_7 ( struct V_8 * V_9 , T_3 * V_14 ,
int V_27 )
{
int V_10 ;
T_1 V_12 ;
T_2 V_13 = ( T_2 ) V_27 << V_23 ;
V_10 = V_9 -> V_20 ( V_9 , V_13 , V_15 , & V_12 , V_14 ) ;
if ( V_10 < 0 || V_12 != V_15 )
return - 1 ;
return 0 ;
}
static int F_8 ( struct V_8 * V_9 , T_2 V_28 , T_3 * V_29 )
{
struct V_30 V_31 ;
int V_10 ;
V_31 . V_32 = V_33 ;
V_31 . V_34 = 0 ;
V_31 . V_35 = V_36 ;
V_31 . V_37 = V_29 ;
V_31 . V_38 = NULL ;
V_10 = V_9 -> V_39 ( V_9 , V_28 , & V_31 ) ;
if ( V_10 < 0 || V_31 . V_40 != V_36 )
return - 1 ;
return 0 ;
}
static int F_9 ( int V_41 , int V_1 )
{
int V_5 ;
int V_42 ;
V_42 = 1 ;
for ( V_5 = 0 ; V_5 < V_1 ; V_5 ++ ) {
V_42 += ( V_41 >> V_5 ) ;
V_42 &= 1 ;
}
return V_42 ;
}
static int F_10 ( T_3 * V_43 )
{
int V_44 , V_42 ;
int V_13 [ 2 ] = { 6 , 11 } ;
int V_45 ;
int V_46 = 0 ;
for ( V_45 = 0 ; V_45 < F_11 ( V_13 ) ; V_45 ++ ) {
V_44 = ( ( int ) V_43 [ V_13 [ V_45 ] ] << 8 ) |
V_43 [ V_13 [ V_45 ] + 1 ] ;
if ( ( V_44 & ~ 0x7FF ) == 0x1000 ) {
V_42 = V_44 & 0x01 ;
V_44 &= 0x7FF ;
V_44 >>= 1 ;
if ( F_9 ( V_44 , 10 ) != V_42 ) {
F_5 ( V_47 ,
L_4
L_5 , V_45 + 1 ,
V_44 ) ;
} else {
V_46 = 1 ;
break;
}
}
}
if ( ! V_46 )
V_44 = - 2 ;
F_5 ( V_48 , L_6 ,
V_44 ) ;
return V_44 ;
}
static int F_12 ( struct V_49 * V_50 )
{
unsigned long V_13 ;
T_3 V_43 [ V_36 ] ;
int V_10 , V_44 , V_51 ;
struct V_8 * V_9 = V_50 -> V_52 . V_9 ;
F_5 ( V_24 , L_7 ,
V_50 -> V_53 ,
( unsigned long ) V_50 -> V_53 * V_50 -> V_54 / 1024 ) ;
for ( V_51 = V_50 -> V_55 + 1 ; V_51 < V_50 -> V_53 ;
V_51 ++ ) {
V_13 = ( unsigned long ) V_51 * V_50 -> V_54 ;
if ( V_9 -> V_19 ( V_9 , V_13 ) )
continue;
V_10 = F_8 ( V_9 , V_13 , V_43 ) ;
if ( V_10 < 0 ) {
F_5 ( V_47 ,
L_8 ,
V_13 ) ;
return - 1 ;
}
V_44 = F_10 ( V_43 ) ;
if ( V_44 >= 0 &&
V_44 < V_56 ) {
int V_57 ;
V_57 = V_51 / V_58 ;
V_44 += V_57 * V_56 ;
V_50 -> V_59 [ V_44 ] =
( unsigned short ) V_51 ;
F_5 ( V_60 ,
L_9
L_10 ,
V_51 , V_44 , V_57 ) ;
}
}
return 0 ;
}
static void F_13 ( struct V_61 * V_62 , struct V_8 * V_9 )
{
struct V_49 * V_50 ;
int V_11 ;
if ( V_9 -> type != V_63 || V_9 -> V_64 != V_36 ||
V_9 -> V_1 > V_65 )
return;
V_11 = F_2 ( V_9 ) ;
if ( V_11 == - 1 )
return;
V_50 = F_14 ( sizeof( struct V_49 ) , V_16 ) ;
if ( ! V_50 ) {
F_4 ( V_21
L_11 ) ;
return;
}
V_50 -> V_52 . V_9 = V_9 ;
V_50 -> V_52 . V_66 = - 1 ;
V_50 -> V_52 . V_62 = V_62 ;
V_50 -> V_52 . V_67 = 1 ;
V_50 -> V_55 = V_11 / ( V_9 -> V_18 >> V_23 ) ;
V_50 -> V_54 = V_9 -> V_18 ;
V_50 -> V_53 = ( V_68 ) V_9 -> V_1 / V_9 -> V_18 ;
F_5 ( V_24 ,
L_12 ,
V_50 -> V_55 , V_50 -> V_54 , V_50 -> V_53 ,
F_15 ( V_50 -> V_53 , V_58 ) ) ;
V_50 -> V_69 = 16 ;
V_50 -> V_70 = 32 ;
F_1 ( V_9 -> V_1 , NULL , & V_50 -> V_69 , & V_50 -> V_70 ) ;
V_50 -> V_71 = ( unsigned short ) ( ( ( V_68 ) V_9 -> V_1 >> V_23 ) /
( ( long ) V_50 -> V_70 * ( long ) V_50 -> V_69 ) ) ;
F_5 ( V_24 , L_13 ,
V_50 -> V_71 , V_50 -> V_69 , V_50 -> V_70 ,
( long ) V_50 -> V_71 * ( long ) V_50 -> V_69 *
( long ) V_50 -> V_70 ) ;
V_50 -> V_52 . V_1 = ( long ) V_50 -> V_69 * ( long ) V_50 -> V_71 *
( long ) V_50 -> V_70 ;
V_50 -> V_59 = F_3 ( sizeof( V_50 -> V_59 [ 0 ] ) *
V_50 -> V_53 , V_16 ) ;
if ( ! V_50 -> V_59 ) {
F_4 ( V_21
L_11 ) ;
goto V_72;
}
memset ( V_50 -> V_59 , 0xff , sizeof( V_50 -> V_59 [ 0 ] ) *
V_50 -> V_53 ) ;
if ( F_12 ( V_50 ) < 0 )
goto V_72;
if ( F_16 ( & V_50 -> V_52 ) )
goto V_72;
F_4 ( V_73 L_14 ,
V_50 -> V_52 . V_66 + 'a' , V_9 -> V_26 , V_9 -> V_25 ) ;
return;
V_72:
F_6 ( V_50 -> V_59 ) ;
F_6 ( V_50 ) ;
}
static void F_17 ( struct V_74 * V_75 )
{
struct V_49 * V_50 = (struct V_49 * ) V_75 ;
F_5 ( V_24 , L_15 , V_75 -> V_66 ) ;
F_18 ( V_75 ) ;
F_6 ( V_50 -> V_59 ) ;
}
static int F_19 ( struct V_74 * V_75 ,
unsigned long V_76 , char * V_29 )
{
struct V_49 * V_50 = (struct V_49 * ) V_75 ;
int V_77 , V_13 , V_44 ;
V_77 = V_50 -> V_54 >> V_23 ;
V_13 = ( int ) ( V_76 % V_77 ) ;
V_44 = ( int ) ( V_76 / V_77 ) ;
F_5 ( V_48 ,
L_16
L_17 , V_76 , V_77 , V_13 ,
V_44 ) ;
if ( V_44 >= V_50 -> V_53 )
F_20 () ;
V_44 = V_50 -> V_59 [ V_44 ] ;
F_5 ( V_48 ,
L_18 ,
V_44 ) ;
if ( V_44 < 0xffff ) {
unsigned long V_27 ;
V_27 = ( unsigned long ) V_44 * V_77 +
V_13 ;
F_5 ( V_48 ,
L_19 ,
V_27 ) ;
if ( F_7 ( V_50 -> V_52 . V_9 , V_29 , V_27 ) < 0 )
return - V_78 ;
} else {
memset ( V_29 , 0xff , V_15 ) ;
}
return 0 ;
}
static int F_21 ( struct V_74 * V_75 , struct V_79 * V_80 )
{
struct V_49 * V_50 = (struct V_49 * ) V_75 ;
F_5 ( V_24 , L_20 ,
V_50 -> V_71 , V_50 -> V_69 , V_50 -> V_70 ) ;
V_80 -> V_69 = V_50 -> V_69 ;
V_80 -> V_70 = V_50 -> V_70 ;
V_80 -> V_71 = V_50 -> V_71 ;
return 0 ;
}
static int T_4 F_22 ( void )
{
F_4 ( V_73 L_21 ) ;
return F_23 ( & V_81 ) ;
}
static void T_5 F_24 ( void )
{
F_25 ( & V_81 ) ;
}
