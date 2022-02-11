static int F_1 ( struct V_1 * V_2 , int * V_3 )
{
struct V_4 V_5 ;
struct V_6 V_7 ;
unsigned char V_8 [ 2 ] ;
int V_9 ;
F_2 ( & V_5 ) ;
memset ( & V_7 , 0 , sizeof( struct V_6 ) ) ;
V_8 [ 0 ] = V_10 ;
V_8 [ 1 ] = 0xff ;
V_7 . V_11 = V_8 ;
V_7 . V_12 = V_8 ;
V_7 . V_13 = sizeof( V_8 ) ;
F_3 ( & V_7 , & V_5 ) ;
V_9 = F_4 ( V_2 -> V_14 , & V_5 ) ;
if ( V_9 < 0 )
return V_9 ;
* V_3 = V_8 [ 1 ] ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , int V_15 )
{
unsigned char V_16 [ 2 ] ;
int V_3 , V_9 ;
V_16 [ 0 ] = V_15 ? V_17 : V_18 ;
V_9 = F_6 ( V_2 -> V_14 , V_16 , 1 ) ;
if ( V_9 )
return V_9 ;
V_16 [ 0 ] = V_19 ;
V_9 = F_6 ( V_2 -> V_14 , V_16 , 1 ) ;
if ( V_9 )
return V_9 ;
V_16 [ 0 ] = V_20 ;
V_16 [ 1 ] = V_15 ? 0 : V_21 | V_22 ;
V_9 = F_6 ( V_2 -> V_14 , V_16 , 2 ) ;
if ( V_9 )
return V_9 ;
if ( V_15 ) {
V_9 = F_1 ( V_2 , & V_3 ) ;
if ( V_9 )
return V_9 ;
if ( ! ( V_3 & V_23 ) )
return - V_24 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
unsigned long V_25 ;
int V_3 , V_9 ;
V_25 = V_26 + V_27 ;
do {
V_9 = F_1 ( V_2 , & V_3 ) ;
if ( V_9 )
return V_9 ;
if ( ! ( V_3 & V_28 ) )
return 0 ;
F_8 () ;
} while ( ! F_9 ( V_26 , V_25 ) );
return - V_29 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_30 )
{
unsigned char V_16 [ 4 ] ;
int V_9 ;
V_9 = F_5 ( V_2 , 1 ) ;
if ( V_9 )
return V_9 ;
V_16 [ 0 ] = V_31 ;
V_16 [ 1 ] = V_30 >> 16 ;
V_16 [ 2 ] = V_30 >> 8 ;
V_16 [ 3 ] = V_30 ;
V_9 = F_6 ( V_2 -> V_14 , V_16 , 4 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_7 ( V_2 ) ;
if ( V_9 )
return V_9 ;
return F_5 ( V_2 , 0 ) ;
}
static int F_11 ( struct V_32 * V_33 , struct V_34 * V_35 )
{
struct V_1 * V_2 = F_12 ( V_33 ) ;
T_1 V_36 , V_37 ;
int V_9 ;
if ( V_35 -> V_36 + V_35 -> V_13 > V_2 -> V_33 . V_38 )
return - V_39 ;
if ( ( T_1 ) V_35 -> V_13 % V_33 -> V_40 )
return - V_39 ;
if ( ( T_1 ) V_35 -> V_36 % V_33 -> V_40 )
return - V_39 ;
V_36 = V_35 -> V_36 ;
V_37 = V_36 + V_35 -> V_13 ;
F_13 ( & V_2 -> V_41 ) ;
V_9 = F_7 ( V_2 ) ;
if ( V_9 ) {
F_14 ( & V_2 -> V_41 ) ;
return V_9 ;
}
while ( V_36 < V_37 ) {
V_9 = F_10 ( V_2 , V_36 ) ;
if ( V_9 ) {
F_14 ( & V_2 -> V_41 ) ;
V_35 -> V_42 = V_43 ;
F_15 ( & V_2 -> V_14 -> V_44 , L_1 ) ;
return V_9 ;
}
V_36 += V_33 -> V_40 ;
}
F_14 ( & V_2 -> V_41 ) ;
V_35 -> V_42 = V_45 ;
F_16 ( V_35 ) ;
return 0 ;
}
static int F_17 ( struct V_32 * V_33 , T_2 V_46 , T_3 V_13 ,
T_3 * V_47 , unsigned char * V_48 )
{
struct V_1 * V_2 = F_12 ( V_33 ) ;
struct V_6 V_49 [ 2 ] ;
struct V_4 V_50 ;
unsigned char V_16 [ 4 ] ;
int V_51 ;
if ( V_13 == 0 )
return 0 ;
if ( V_46 + V_13 > V_2 -> V_33 . V_38 )
return - V_39 ;
if ( V_47 )
* V_47 = 0 ;
F_2 ( & V_50 ) ;
memset ( & V_49 , 0 , sizeof( V_49 ) ) ;
V_16 [ 0 ] = V_52 ;
V_16 [ 1 ] = V_46 >> 16 ;
V_16 [ 2 ] = V_46 >> 8 ;
V_16 [ 3 ] = V_46 ;
V_49 [ 0 ] . V_11 = V_16 ;
V_49 [ 0 ] . V_13 = sizeof( V_16 ) ;
F_3 ( & V_49 [ 0 ] , & V_50 ) ;
V_49 [ 1 ] . V_12 = V_48 ;
V_49 [ 1 ] . V_13 = V_13 ;
F_3 ( & V_49 [ 1 ] , & V_50 ) ;
F_13 ( & V_2 -> V_41 ) ;
V_51 = F_7 ( V_2 ) ;
if ( V_51 ) {
F_14 ( & V_2 -> V_41 ) ;
return V_51 ;
}
F_4 ( V_2 -> V_14 , & V_50 ) ;
if ( V_47 && V_50 . V_53 > sizeof( V_16 ) )
* V_47 += V_50 . V_53 - sizeof( V_16 ) ;
F_14 ( & V_2 -> V_41 ) ;
return 0 ;
}
static int F_18 ( struct V_32 * V_33 , T_2 V_54 , T_3 V_13 ,
T_3 * V_47 , const unsigned char * V_48 )
{
struct V_1 * V_2 = F_12 ( V_33 ) ;
int V_55 , V_56 , V_51 , V_57 , V_58 = 0 ;
unsigned char V_16 [ 5 ] ;
if ( ! V_13 )
return 0 ;
if ( V_54 + V_13 > V_2 -> V_33 . V_38 )
return - V_39 ;
if ( ( T_1 ) V_54 % V_33 -> V_59 )
return - V_39 ;
F_13 ( & V_2 -> V_41 ) ;
V_51 = F_5 ( V_2 , 1 ) ;
if ( V_51 )
goto V_60;
for ( V_55 = 0 ; V_55 < V_13 ; V_55 += V_33 -> V_59 ) {
V_51 = F_7 ( V_2 ) ;
if ( V_51 )
goto V_60;
V_16 [ 0 ] = V_61 ;
V_16 [ 1 ] = ( V_54 + V_55 ) >> 16 ;
V_16 [ 2 ] = ( V_54 + V_55 ) >> 8 ;
V_16 [ 3 ] = ( V_54 + V_55 ) ;
V_16 [ 4 ] = V_48 [ V_55 ] ;
V_51 = F_6 ( V_2 -> V_14 , V_16 , 5 ) ;
if ( V_51 < 0 )
goto V_60;
V_58 ++ ;
V_57 = F_19 ( T_1 , V_33 -> V_59 , V_13 - V_55 ) ;
for ( V_56 = 1 ; V_56 < V_57 ; V_56 ++ , V_58 ++ ) {
V_51 = F_7 ( V_2 ) ;
if ( V_51 )
goto V_60;
V_16 [ 1 ] = V_48 [ V_55 + V_56 ] ;
V_51 = F_6 ( V_2 -> V_14 , V_16 , 2 ) ;
if ( V_51 )
goto V_60;
}
}
V_60:
V_51 = F_5 ( V_2 , 0 ) ;
if ( V_47 )
* V_47 = V_58 ;
F_14 ( & V_2 -> V_41 ) ;
return V_51 ;
}
static struct V_62 * T_4 F_20 ( struct V_63 * V_14 )
{
struct V_62 * V_62 = NULL ;
struct V_4 V_5 ;
struct V_6 V_7 ;
unsigned char V_8 [ 6 ] ;
int V_55 , V_9 ;
T_5 V_64 ;
F_2 ( & V_5 ) ;
memset ( & V_7 , 0 , sizeof( struct V_6 ) ) ;
V_8 [ 0 ] = V_65 ;
V_8 [ 1 ] = 0 ;
V_8 [ 2 ] = 0 ;
V_8 [ 3 ] = 0 ;
V_8 [ 4 ] = 0xff ;
V_8 [ 5 ] = 0xff ;
V_7 . V_11 = V_8 ;
V_7 . V_12 = V_8 ;
V_7 . V_13 = sizeof( V_8 ) ;
F_3 ( & V_7 , & V_5 ) ;
V_9 = F_4 ( V_14 , & V_5 ) ;
if ( V_9 < 0 ) {
F_15 ( & V_14 -> V_44 , L_2 ) ;
return NULL ;
}
V_64 = ( V_8 [ 4 ] << 8 ) | V_8 [ 5 ] ;
for ( V_55 = 0 ; V_55 < F_21 ( V_66 ) ; V_55 ++ )
if ( V_66 [ V_55 ] . V_67 == V_64 )
V_62 = & V_66 [ V_55 ] ;
if ( ! V_62 )
F_15 ( & V_14 -> V_44 , L_3 , V_64 ) ;
return V_62 ;
}
static int T_4 F_22 ( struct V_63 * V_14 )
{
struct V_62 * V_62 ;
struct V_1 * V_2 ;
struct V_68 * V_69 ;
int V_51 ;
V_62 = F_20 ( V_14 ) ;
if ( ! V_62 )
return - V_70 ;
V_2 = F_23 ( sizeof( struct V_1 ) , V_71 ) ;
if ( ! V_2 )
return - V_72 ;
V_2 -> V_14 = V_14 ;
F_24 ( & V_2 -> V_41 ) ;
F_25 ( & V_14 -> V_44 , V_2 ) ;
V_69 = V_14 -> V_44 . V_73 ;
if ( V_69 && V_69 -> V_74 )
V_2 -> V_33 . V_74 = V_69 -> V_74 ;
else
V_2 -> V_33 . V_74 = F_26 ( & V_14 -> V_44 ) ;
V_2 -> V_33 . type = V_75 ;
V_2 -> V_33 . V_76 = V_77 ;
V_2 -> V_33 . V_40 = V_62 -> V_78 ;
V_2 -> V_33 . V_59 = V_62 -> V_79 ;
V_2 -> V_33 . V_38 = V_62 -> V_79 * V_62 -> V_80 ;
V_2 -> V_33 . V_81 = F_11 ;
V_2 -> V_33 . V_82 = F_17 ;
V_2 -> V_33 . V_83 = F_18 ;
F_27 ( & V_14 -> V_44 , L_4 , V_62 -> V_74 ,
( long long ) V_2 -> V_33 . V_38 >> 10 ) ;
F_28 ( L_5
L_6 ,
V_2 -> V_33 . V_74 ,
( long long ) V_2 -> V_33 . V_38 , ( long long ) ( V_2 -> V_33 . V_38 >> 20 ) ,
V_2 -> V_33 . V_40 , V_2 -> V_33 . V_40 / 1024 ,
V_2 -> V_33 . V_84 ) ;
V_51 = F_29 ( & V_2 -> V_33 , NULL , 0 ,
V_69 ? V_69 -> V_85 : NULL ,
V_69 ? V_69 -> V_86 : 0 ) ;
if ( V_51 ) {
F_30 ( V_2 ) ;
F_25 ( & V_14 -> V_44 , NULL ) ;
return - V_70 ;
}
return 0 ;
}
static int T_6 F_31 ( struct V_63 * V_14 )
{
struct V_1 * V_2 = F_32 ( & V_14 -> V_44 ) ;
int V_51 ;
V_51 = F_33 ( & V_2 -> V_33 ) ;
if ( V_51 == 0 )
F_30 ( V_2 ) ;
return V_51 ;
}
static int T_7 F_34 ( void )
{
return F_35 ( & V_87 ) ;
}
static void T_8 F_36 ( void )
{
F_37 ( & V_87 ) ;
}
