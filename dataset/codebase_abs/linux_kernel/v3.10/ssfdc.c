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
if ( F_4 ( V_9 , V_13 ) ) {
V_10 = F_5 ( V_9 , V_13 , V_15 , & V_12 ,
V_14 ) ;
if ( V_10 < 0 || V_12 != V_15 ) {
F_6 ( V_19
L_1 ) ;
} else if ( ! memcmp ( V_14 , V_20 ,
sizeof( V_20 ) ) ) {
V_11 = ( int ) ( V_13 >> V_21 ) ;
} else {
F_7 ( L_2
L_3 , V_9 -> V_22 ,
V_9 -> V_23 ) ;
}
break;
}
}
F_8 ( V_14 ) ;
V_17:
return V_11 ;
}
static int F_9 ( struct V_8 * V_9 , T_3 * V_14 ,
int V_24 )
{
int V_10 ;
T_1 V_12 ;
T_2 V_13 = ( T_2 ) V_24 << V_21 ;
V_10 = F_5 ( V_9 , V_13 , V_15 , & V_12 , V_14 ) ;
if ( V_10 < 0 || V_12 != V_15 )
return - 1 ;
return 0 ;
}
static int F_10 ( struct V_8 * V_9 , T_2 V_25 , T_3 * V_26 )
{
struct V_27 V_28 ;
int V_10 ;
V_28 . V_29 = V_30 ;
V_28 . V_31 = 0 ;
V_28 . V_32 = V_33 ;
V_28 . V_34 = V_26 ;
V_28 . V_35 = NULL ;
V_10 = F_11 ( V_9 , V_25 , & V_28 ) ;
if ( V_10 < 0 || V_28 . V_36 != V_33 )
return - 1 ;
return 0 ;
}
static int F_12 ( int V_37 , int V_1 )
{
int V_5 ;
int V_38 ;
V_38 = 1 ;
for ( V_5 = 0 ; V_5 < V_1 ; V_5 ++ ) {
V_38 += ( V_37 >> V_5 ) ;
V_38 &= 1 ;
}
return V_38 ;
}
static int F_13 ( T_3 * V_39 )
{
int V_40 , V_38 ;
int V_13 [ 2 ] = { 6 , 11 } ;
int V_41 ;
int V_42 = 0 ;
for ( V_41 = 0 ; V_41 < F_14 ( V_13 ) ; V_41 ++ ) {
V_40 = ( ( int ) V_39 [ V_13 [ V_41 ] ] << 8 ) |
V_39 [ V_13 [ V_41 ] + 1 ] ;
if ( ( V_40 & ~ 0x7FF ) == 0x1000 ) {
V_38 = V_40 & 0x01 ;
V_40 &= 0x7FF ;
V_40 >>= 1 ;
if ( F_12 ( V_40 , 10 ) != V_38 ) {
F_7 ( L_4
L_5 , V_41 + 1 ,
V_40 ) ;
} else {
V_42 = 1 ;
break;
}
}
}
if ( ! V_42 )
V_40 = - 2 ;
F_7 ( L_6 ,
V_40 ) ;
return V_40 ;
}
static int F_15 ( struct V_43 * V_44 )
{
unsigned long V_13 ;
T_3 V_39 [ V_33 ] ;
int V_10 , V_40 , V_45 ;
struct V_8 * V_9 = V_44 -> V_46 . V_9 ;
F_7 ( L_7 ,
V_44 -> V_47 ,
( unsigned long ) V_44 -> V_47 * V_44 -> V_48 / 1024 ) ;
for ( V_45 = V_44 -> V_49 + 1 ; V_45 < V_44 -> V_47 ;
V_45 ++ ) {
V_13 = ( unsigned long ) V_45 * V_44 -> V_48 ;
if ( F_4 ( V_9 , V_13 ) )
continue;
V_10 = F_10 ( V_9 , V_13 , V_39 ) ;
if ( V_10 < 0 ) {
F_7 ( L_8 ,
V_13 ) ;
return - 1 ;
}
V_40 = F_13 ( V_39 ) ;
if ( V_40 >= 0 &&
V_40 < V_50 ) {
int V_51 ;
V_51 = V_45 / V_52 ;
V_40 += V_51 * V_50 ;
V_44 -> V_53 [ V_40 ] =
( unsigned short ) V_45 ;
F_7 ( L_9
L_10 ,
V_45 , V_40 , V_51 ) ;
}
}
return 0 ;
}
static void F_16 ( struct V_54 * V_55 , struct V_8 * V_9 )
{
struct V_43 * V_44 ;
int V_11 ;
if ( V_9 -> type != V_56 || V_9 -> V_57 != V_33 ||
V_9 -> V_1 > V_58 )
return;
V_11 = F_2 ( V_9 ) ;
if ( V_11 == - 1 )
return;
V_44 = F_17 ( sizeof( struct V_43 ) , V_16 ) ;
if ( ! V_44 )
return;
V_44 -> V_46 . V_9 = V_9 ;
V_44 -> V_46 . V_59 = - 1 ;
V_44 -> V_46 . V_55 = V_55 ;
V_44 -> V_46 . V_60 = 1 ;
V_44 -> V_49 = V_11 / ( V_9 -> V_18 >> V_21 ) ;
V_44 -> V_48 = V_9 -> V_18 ;
V_44 -> V_47 = ( V_61 ) V_9 -> V_1 / V_9 -> V_18 ;
F_7 ( L_11 ,
V_44 -> V_49 , V_44 -> V_48 , V_44 -> V_47 ,
F_18 ( V_44 -> V_47 , V_52 ) ) ;
V_44 -> V_62 = 16 ;
V_44 -> V_63 = 32 ;
F_1 ( V_9 -> V_1 , NULL , & V_44 -> V_62 , & V_44 -> V_63 ) ;
V_44 -> V_64 = ( unsigned short ) ( ( ( V_61 ) V_9 -> V_1 >> V_21 ) /
( ( long ) V_44 -> V_63 * ( long ) V_44 -> V_62 ) ) ;
F_7 ( L_12 ,
V_44 -> V_64 , V_44 -> V_62 , V_44 -> V_63 ,
( long ) V_44 -> V_64 * ( long ) V_44 -> V_62 *
( long ) V_44 -> V_63 ) ;
V_44 -> V_46 . V_1 = ( long ) V_44 -> V_62 * ( long ) V_44 -> V_64 *
( long ) V_44 -> V_63 ;
V_44 -> V_53 = F_3 ( sizeof( V_44 -> V_53 [ 0 ] ) *
V_44 -> V_47 , V_16 ) ;
if ( ! V_44 -> V_53 )
goto V_65;
memset ( V_44 -> V_53 , 0xff , sizeof( V_44 -> V_53 [ 0 ] ) *
V_44 -> V_47 ) ;
if ( F_15 ( V_44 ) < 0 )
goto V_65;
if ( F_19 ( & V_44 -> V_46 ) )
goto V_65;
F_6 ( V_66 L_13 ,
V_44 -> V_46 . V_59 + 'a' , V_9 -> V_23 , V_9 -> V_22 ) ;
return;
V_65:
F_8 ( V_44 -> V_53 ) ;
F_8 ( V_44 ) ;
}
static void F_20 ( struct V_67 * V_68 )
{
struct V_43 * V_44 = (struct V_43 * ) V_68 ;
F_7 ( L_14 , V_68 -> V_59 ) ;
F_21 ( V_68 ) ;
F_8 ( V_44 -> V_53 ) ;
}
static int F_22 ( struct V_67 * V_68 ,
unsigned long V_69 , char * V_26 )
{
struct V_43 * V_44 = (struct V_43 * ) V_68 ;
int V_70 , V_13 , V_40 ;
V_70 = V_44 -> V_48 >> V_21 ;
V_13 = ( int ) ( V_69 % V_70 ) ;
V_40 = ( int ) ( V_69 / V_70 ) ;
F_7 ( L_15
L_16 , V_69 , V_70 , V_13 ,
V_40 ) ;
if ( V_40 >= V_44 -> V_47 )
F_23 () ;
V_40 = V_44 -> V_53 [ V_40 ] ;
F_7 ( L_17 ,
V_40 ) ;
if ( V_40 < 0xffff ) {
unsigned long V_24 ;
V_24 = ( unsigned long ) V_40 * V_70 +
V_13 ;
F_7 ( L_18 ,
V_24 ) ;
if ( F_9 ( V_44 -> V_46 . V_9 , V_26 , V_24 ) < 0 )
return - V_71 ;
} else {
memset ( V_26 , 0xff , V_15 ) ;
}
return 0 ;
}
static int F_24 ( struct V_67 * V_68 , struct V_72 * V_73 )
{
struct V_43 * V_44 = (struct V_43 * ) V_68 ;
F_7 ( L_19 ,
V_44 -> V_64 , V_44 -> V_62 , V_44 -> V_63 ) ;
V_73 -> V_62 = V_44 -> V_62 ;
V_73 -> V_63 = V_44 -> V_63 ;
V_73 -> V_64 = V_44 -> V_64 ;
return 0 ;
}
static int T_4 F_25 ( void )
{
F_6 ( V_66 L_20 ) ;
return F_26 ( & V_74 ) ;
}
static void T_5 F_27 ( void )
{
F_28 ( & V_74 ) ;
}
