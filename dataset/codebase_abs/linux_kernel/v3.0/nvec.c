int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_5 )
{
return F_2 ( & V_2 -> V_6 , V_4 ) ;
}
static int F_3 ( struct V_3 * V_4 , unsigned long V_7 ,
void * V_8 )
{
unsigned char * V_9 = ( unsigned char * ) V_8 ;
int V_10 ;
if( V_7 != V_11 )
return V_12 ;
F_4 ( L_1 , V_7 ) ;
for ( V_10 = 0 ; V_10 < V_9 [ 1 ] ; V_10 ++ )
F_4 ( L_2 , V_9 [ V_10 + 2 ] ) ;
F_4 ( L_3 ) ;
return V_13 ;
}
void F_5 ( struct V_1 * V_2 , unsigned char * V_8 , short V_14 )
{
struct V_15 * V_9 = F_6 ( sizeof( struct V_15 ) , V_16 ) ;
V_9 -> V_8 = F_6 ( V_14 , V_16 ) ;
V_9 -> V_8 [ 0 ] = V_14 ;
memcpy ( V_9 -> V_8 + 1 , V_8 , V_14 ) ;
V_9 -> V_14 = V_14 + 1 ;
V_9 -> V_17 = 0 ;
F_7 ( & V_9 -> V_18 ) ;
F_8 ( & V_9 -> V_18 , & V_2 -> V_19 ) ;
F_9 ( V_2 -> V_20 , 0 ) ;
}
static void F_10 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_11 ( V_22 , struct V_1 , V_23 ) ;
if( ! F_12 ( & V_2 -> V_19 ) ) {
F_9 ( V_2 -> V_20 , 0 ) ;
}
}
static int F_13 ( struct V_1 * V_2 , struct V_15 * V_9 )
{
int V_10 ;
if( ( V_9 -> V_8 [ 0 ] & 1 << 7 ) == 0 && V_9 -> V_8 [ 3 ] ) {
F_14 ( V_2 -> V_24 , L_4 , V_9 -> V_8 [ 0 ] ,
V_9 -> V_8 [ 1 ] , V_9 -> V_8 [ 2 ] , V_9 -> V_8 [ 3 ] ) ;
return - V_25 ;
}
if ( ( V_9 -> V_8 [ 0 ] >> 7 ) == 1 && ( V_9 -> V_8 [ 0 ] & 0x0f ) == 5 )
{
F_15 ( V_2 -> V_24 , L_5 ) ;
for ( V_10 = 0 ; V_10 < V_9 -> V_8 [ 1 ] ; V_10 ++ )
F_15 ( V_2 -> V_24 , L_6 , V_9 -> V_8 [ 2 + V_10 ] ) ;
F_15 ( V_2 -> V_24 , L_3 ) ;
}
F_16 ( & V_2 -> V_6 , V_9 -> V_8 [ 0 ] & 0x8f , V_9 -> V_8 ) ;
return 0 ;
}
static struct V_15 * F_17 ( struct V_1 * V_2 , unsigned char * V_8 , short V_14 )
{
F_18 ( & V_2 -> V_26 ) ;
V_2 -> V_27 = ( V_8 [ 1 ] << 8 ) + V_8 [ 0 ] ;
F_5 ( V_2 , V_8 , V_14 ) ;
F_19 ( V_2 -> V_24 , L_7 , V_2 -> V_27 ) ;
F_20 ( & V_2 -> V_28 ) ;
F_19 ( V_2 -> V_24 , L_8 ) ;
F_21 ( & V_2 -> V_26 ) ;
return V_2 -> V_29 ;
}
static void F_22 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_11 ( V_22 , struct V_1 , V_30 ) ;
struct V_15 * V_9 ;
while( ! F_12 ( & V_2 -> V_31 ) )
{
V_9 = F_23 ( & V_2 -> V_31 , struct V_15 , V_18 ) ;
F_24 ( & V_9 -> V_18 ) ;
if( V_2 -> V_27 == ( V_9 -> V_8 [ 2 ] << 8 ) + V_9 -> V_8 [ 0 ] )
{
F_19 ( V_2 -> V_24 , L_9 ) ;
V_2 -> V_27 = 0 ;
V_2 -> V_29 = V_9 ;
F_25 ( & V_2 -> V_28 ) ;
} else {
F_13 ( V_2 , V_9 ) ;
if( ( ! V_9 ) || ( ! V_9 -> V_8 ) )
F_15 ( V_2 -> V_24 , L_10 ) ;
else {
F_26 ( V_9 -> V_8 ) ;
F_26 ( V_9 ) ;
}
}
}
}
static T_1 F_27 ( int V_32 , void * V_24 )
{
unsigned long V_33 ;
unsigned long V_34 ;
unsigned char V_35 ;
struct V_15 * V_9 ;
struct V_1 * V_2 = (struct V_1 * ) V_24 ;
unsigned char * V_36 = V_2 -> V_36 ;
V_33 = F_28 ( V_36 + V_37 ) ;
if( ! ( V_33 & V_38 ) )
{
F_15 ( V_2 -> V_24 , L_11 ) ;
goto V_39;
}
if( V_33 & V_40 && ! ( V_33 & V_41 ) )
{
V_2 -> V_42 = V_43 ;
if( V_2 -> V_44 -> V_14 > 1 )
{
F_8 ( & V_2 -> V_44 -> V_18 , & V_2 -> V_31 ) ;
F_29 ( & V_2 -> V_30 ) ;
} else {
F_26 ( V_2 -> V_44 -> V_8 ) ;
F_26 ( V_2 -> V_44 ) ;
}
return V_45 ;
} else if( V_33 & V_46 )
{
if( V_33 & V_41 )
F_30 ( 3 ) ;
if( V_33 & V_41 )
{
V_2 -> V_42 = V_47 ;
} else {
}
if( F_12 ( & V_2 -> V_19 ) )
{
F_14 ( V_2 -> V_24 , L_12 ) ;
V_35 = 0x8a ;
F_5 ( V_2 , L_13 , 2 ) ;
} else {
V_9 = F_23 ( & V_2 -> V_19 , struct V_15 , V_18 ) ;
if( V_9 -> V_17 < V_9 -> V_14 ) {
V_35 = V_9 -> V_8 [ V_9 -> V_17 ] ;
V_9 -> V_17 ++ ;
} else {
F_14 ( V_2 -> V_24 , L_14 , V_9 -> V_14 ) ;
V_35 = 0x01 ;
}
if( V_9 -> V_17 >= V_9 -> V_14 )
{
F_24 ( & V_9 -> V_18 ) ;
F_26 ( V_9 -> V_8 ) ;
F_26 ( V_9 ) ;
F_29 ( & V_2 -> V_23 ) ;
V_2 -> V_42 = V_43 ;
}
}
F_31 ( V_35 , V_36 + V_48 ) ;
F_9 ( V_2 -> V_20 , 1 ) ;
F_19 ( V_2 -> V_24 , L_15 , V_35 ) ;
goto V_39;
} else {
V_34 = F_28 ( V_36 + V_48 ) ;
if( V_33 & V_41 ) {
F_31 ( 0 , V_36 + V_48 ) ;
goto V_39;
}
if ( V_2 -> V_42 == V_43 )
{
V_2 -> V_42 = V_49 ;
V_9 = F_6 ( sizeof( struct V_15 ) , V_16 ) ;
V_9 -> V_8 = F_6 ( 32 , V_16 ) ;
F_7 ( & V_9 -> V_18 ) ;
V_2 -> V_44 = V_9 ;
} else
V_9 = V_2 -> V_44 ;
F_32 ( V_9 -> V_17 > 32 ) ;
V_9 -> V_8 [ V_9 -> V_17 ] = V_34 ;
V_9 -> V_17 ++ ;
V_9 -> V_14 = V_9 -> V_17 ;
F_19 ( V_2 -> V_24 , L_16 , V_34 , V_9 -> V_17 ) ;
}
V_39:
return V_45 ;
}
static int T_2 F_33 ( struct V_1 * V_2 , struct V_50 * V_51 )
{
struct V_52 * V_53 ;
V_53 = F_34 ( V_51 -> V_54 , V_51 -> V_55 ) ;
V_53 -> V_24 . V_56 = V_2 -> V_24 ;
V_53 -> V_24 . V_57 = V_51 -> V_57 ;
return F_35 ( V_53 ) ;
}
static void F_36 ( struct V_58 * V_59 , unsigned char * V_36 ,
struct V_60 * V_61 )
{
T_3 V_62 ;
F_37 ( V_61 ) ;
F_38 ( V_61 ) ;
F_30 ( 2 ) ;
F_39 ( V_61 ) ;
F_31 ( V_59 -> V_63 >> 1 , V_36 + V_64 ) ;
F_31 ( 0 , V_36 + V_65 ) ;
F_31 ( 0x1E , V_36 + V_66 ) ;
V_62 = V_67 | V_68 |
( 0x2 << V_69 ) ;
F_31 ( V_62 , V_36 + V_70 ) ;
F_31 ( V_71 , V_36 + V_72 ) ;
F_40 ( V_61 ) ;
}
static void F_41 ( void )
{
F_5 ( V_73 , V_74 , 3 ) ;
F_5 ( V_73 , L_17 , 2 ) ;
}
static int T_2 F_42 ( struct V_52 * V_53 )
{
int V_75 , V_10 , V_76 ;
struct V_60 * V_61 ;
struct V_58 * V_59 = V_53 -> V_24 . V_57 ;
struct V_1 * V_2 ;
struct V_15 * V_9 ;
unsigned char * V_36 ;
V_2 = F_6 ( sizeof( struct V_1 ) , V_77 ) ;
if( V_2 == NULL ) {
F_14 ( & V_53 -> V_24 , L_18 ) ;
return - V_78 ;
}
F_43 ( V_53 , V_2 ) ;
V_2 -> V_24 = & V_53 -> V_24 ;
V_2 -> V_20 = V_59 -> V_20 ;
V_2 -> V_32 = V_59 -> V_32 ;
V_36 = F_44 ( V_59 -> V_79 , V_59 -> V_14 ) ;
if( ! V_36 ) {
F_14 ( V_2 -> V_24 , L_19 ) ;
goto V_80;
}
V_2 -> V_36 = V_36 ;
V_61 = F_45 ( V_59 -> clock , NULL ) ;
if( F_46 ( V_61 ) ) {
F_14 ( V_2 -> V_24 , L_20 ) ;
goto V_80;
}
F_36 ( V_59 , V_36 , V_61 ) ;
V_75 = F_47 ( V_2 -> V_32 , F_27 , V_81 , L_21 , V_2 ) ;
if( V_75 ) {
F_14 ( V_2 -> V_24 , L_22 ) ;
goto V_80;
}
F_37 ( V_61 ) ;
F_48 ( V_61 , 8 * 80000 ) ;
V_75 = F_49 ( V_2 -> V_20 , L_23 ) ;
if( V_75 < 0 )
F_14 ( V_2 -> V_24 , L_24 ) ;
F_50 ( V_2 -> V_20 ) ;
F_51 ( V_2 -> V_20 , 1 ) ;
F_9 ( V_2 -> V_20 , 1 ) ;
F_52 ( & V_2 -> V_6 ) ;
F_53 ( & V_2 -> V_28 ) ;
F_54 ( & V_2 -> V_26 , 1 ) ;
F_7 ( & V_2 -> V_19 ) ;
F_7 ( & V_2 -> V_31 ) ;
F_55 ( & V_2 -> V_30 , F_22 ) ;
F_55 ( & V_2 -> V_23 , F_10 ) ;
F_5 ( V_2 , V_82 ,
sizeof( V_82 ) ) ;
F_56 ( V_2 ) ;
#ifdef F_57
F_58 ( V_2 ) ;
#endif
for ( V_10 = 0 ; V_10 < V_59 -> V_83 ; V_10 ++ ) {
V_76 = F_33 ( V_2 , & V_59 -> V_84 [ V_10 ] ) ;
}
V_2 -> F_3 . V_85 = F_3 ;
F_1 ( V_2 , & V_2 -> F_3 , 0 ) ;
V_73 = V_2 ;
V_86 = F_41 ;
V_9 = F_17 ( V_2 , V_87 ,
sizeof( V_87 ) ) ;
F_15 ( V_2 -> V_24 , L_25 ,
V_9 -> V_8 [ 4 ] , V_9 -> V_8 [ 5 ] , V_9 -> V_8 [ 6 ] , V_9 -> V_8 [ 7 ] ) ;
F_26 ( V_9 -> V_8 ) ;
F_26 ( V_9 ) ;
F_5 ( V_2 , L_26 , 4 ) ;
F_5 ( V_2 , L_27 , 7 ) ;
F_5 ( V_2 , L_28 , 7 ) ;
return 0 ;
V_80:
F_26 ( V_2 ) ;
return - V_78 ;
}
static int T_4 F_59 ( struct V_52 * V_53 )
{
return 0 ;
}
static int F_60 ( struct V_52 * V_53 , T_5 V_42 )
{
struct V_1 * V_2 = F_61 ( V_53 ) ;
F_19 ( V_2 -> V_24 , L_29 ) ;
F_5 ( V_2 , V_74 , 3 ) ;
F_5 ( V_2 , L_30 , 2 ) ;
return 0 ;
}
static int F_62 ( struct V_52 * V_53 ) {
struct V_1 * V_2 = F_61 ( V_53 ) ;
F_19 ( V_2 -> V_24 , L_31 ) ;
F_5 ( V_2 , V_82 , 3 ) ;
return 0 ;
}
static int T_6 F_63 ( void )
{
return F_64 ( & V_88 ) ;
}
