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
if ( ( T_1 ) V_35 -> V_13 % V_33 -> V_38 )
return - V_39 ;
if ( ( T_1 ) V_35 -> V_36 % V_33 -> V_38 )
return - V_39 ;
V_36 = V_35 -> V_36 ;
V_37 = V_36 + V_35 -> V_13 ;
F_13 ( & V_2 -> V_40 ) ;
V_9 = F_7 ( V_2 ) ;
if ( V_9 ) {
F_14 ( & V_2 -> V_40 ) ;
return V_9 ;
}
while ( V_36 < V_37 ) {
V_9 = F_10 ( V_2 , V_36 ) ;
if ( V_9 ) {
F_14 ( & V_2 -> V_40 ) ;
V_35 -> V_41 = V_42 ;
F_15 ( & V_2 -> V_14 -> V_43 , L_1 ) ;
return V_9 ;
}
V_36 += V_33 -> V_38 ;
}
F_14 ( & V_2 -> V_40 ) ;
V_35 -> V_41 = V_44 ;
F_16 ( V_35 ) ;
return 0 ;
}
static int F_17 ( struct V_32 * V_33 , T_2 V_45 , T_3 V_13 ,
T_3 * V_46 , unsigned char * V_47 )
{
struct V_1 * V_2 = F_12 ( V_33 ) ;
struct V_6 V_48 [ 2 ] ;
struct V_4 V_49 ;
unsigned char V_16 [ 4 ] ;
int V_50 ;
F_2 ( & V_49 ) ;
memset ( & V_48 , 0 , sizeof( V_48 ) ) ;
V_16 [ 0 ] = V_51 ;
V_16 [ 1 ] = V_45 >> 16 ;
V_16 [ 2 ] = V_45 >> 8 ;
V_16 [ 3 ] = V_45 ;
V_48 [ 0 ] . V_11 = V_16 ;
V_48 [ 0 ] . V_13 = sizeof( V_16 ) ;
F_3 ( & V_48 [ 0 ] , & V_49 ) ;
V_48 [ 1 ] . V_12 = V_47 ;
V_48 [ 1 ] . V_13 = V_13 ;
F_3 ( & V_48 [ 1 ] , & V_49 ) ;
F_13 ( & V_2 -> V_40 ) ;
V_50 = F_7 ( V_2 ) ;
if ( V_50 ) {
F_14 ( & V_2 -> V_40 ) ;
return V_50 ;
}
F_4 ( V_2 -> V_14 , & V_49 ) ;
if ( V_46 && V_49 . V_52 > sizeof( V_16 ) )
* V_46 += V_49 . V_52 - sizeof( V_16 ) ;
F_14 ( & V_2 -> V_40 ) ;
return 0 ;
}
static int F_18 ( struct V_32 * V_33 , T_2 V_53 , T_3 V_13 ,
T_3 * V_46 , const unsigned char * V_47 )
{
struct V_1 * V_2 = F_12 ( V_33 ) ;
int V_54 , V_55 , V_50 , V_56 , V_57 = 0 ;
unsigned char V_16 [ 5 ] ;
if ( ( T_1 ) V_53 % V_33 -> V_58 )
return - V_39 ;
F_13 ( & V_2 -> V_40 ) ;
V_50 = F_5 ( V_2 , 1 ) ;
if ( V_50 )
goto V_59;
for ( V_54 = 0 ; V_54 < V_13 ; V_54 += V_33 -> V_58 ) {
V_50 = F_7 ( V_2 ) ;
if ( V_50 )
goto V_59;
V_16 [ 0 ] = V_60 ;
V_16 [ 1 ] = ( V_53 + V_54 ) >> 16 ;
V_16 [ 2 ] = ( V_53 + V_54 ) >> 8 ;
V_16 [ 3 ] = ( V_53 + V_54 ) ;
V_16 [ 4 ] = V_47 [ V_54 ] ;
V_50 = F_6 ( V_2 -> V_14 , V_16 , 5 ) ;
if ( V_50 < 0 )
goto V_59;
V_57 ++ ;
V_56 = F_19 ( T_1 , V_33 -> V_58 , V_13 - V_54 ) ;
for ( V_55 = 1 ; V_55 < V_56 ; V_55 ++ , V_57 ++ ) {
V_50 = F_7 ( V_2 ) ;
if ( V_50 )
goto V_59;
V_16 [ 1 ] = V_47 [ V_54 + V_55 ] ;
V_50 = F_6 ( V_2 -> V_14 , V_16 , 2 ) ;
if ( V_50 )
goto V_59;
}
}
V_59:
V_50 = F_5 ( V_2 , 0 ) ;
if ( V_46 )
* V_46 = V_57 ;
F_14 ( & V_2 -> V_40 ) ;
return V_50 ;
}
static struct V_61 * F_20 ( struct V_62 * V_14 )
{
struct V_61 * V_61 = NULL ;
struct V_4 V_5 ;
struct V_6 V_7 ;
unsigned char V_8 [ 6 ] ;
int V_54 , V_9 ;
T_4 V_63 ;
F_2 ( & V_5 ) ;
memset ( & V_7 , 0 , sizeof( struct V_6 ) ) ;
V_8 [ 0 ] = V_64 ;
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
F_15 ( & V_14 -> V_43 , L_2 ) ;
return NULL ;
}
V_63 = ( V_8 [ 4 ] << 8 ) | V_8 [ 5 ] ;
for ( V_54 = 0 ; V_54 < F_21 ( V_65 ) ; V_54 ++ )
if ( V_65 [ V_54 ] . V_66 == V_63 )
V_61 = & V_65 [ V_54 ] ;
if ( ! V_61 )
F_15 ( & V_14 -> V_43 , L_3 , V_63 ) ;
return V_61 ;
}
static int F_22 ( struct V_62 * V_14 )
{
struct V_61 * V_61 ;
struct V_1 * V_2 ;
struct V_67 * V_68 ;
int V_50 ;
V_61 = F_20 ( V_14 ) ;
if ( ! V_61 )
return - V_69 ;
V_2 = F_23 ( & V_14 -> V_43 , sizeof( * V_2 ) , V_70 ) ;
if ( ! V_2 )
return - V_71 ;
V_2 -> V_14 = V_14 ;
F_24 ( & V_2 -> V_40 ) ;
F_25 ( V_14 , V_2 ) ;
V_68 = F_26 ( & V_14 -> V_43 ) ;
if ( V_68 && V_68 -> V_72 )
V_2 -> V_33 . V_72 = V_68 -> V_72 ;
V_2 -> V_33 . V_43 . V_73 = & V_14 -> V_43 ;
V_2 -> V_33 . type = V_74 ;
V_2 -> V_33 . V_75 = V_76 ;
V_2 -> V_33 . V_38 = V_61 -> V_77 ;
V_2 -> V_33 . V_58 = V_61 -> V_78 ;
V_2 -> V_33 . V_79 = V_61 -> V_78 ;
V_2 -> V_33 . V_80 = V_61 -> V_78 * V_61 -> V_81 ;
V_2 -> V_33 . V_82 = F_11 ;
V_2 -> V_33 . V_83 = F_17 ;
V_2 -> V_33 . V_84 = F_18 ;
F_27 ( & V_14 -> V_43 , L_4 , V_61 -> V_72 ,
( long long ) V_2 -> V_33 . V_80 >> 10 ) ;
F_28 ( L_5
L_6 ,
V_2 -> V_33 . V_72 ,
( long long ) V_2 -> V_33 . V_80 , ( long long ) ( V_2 -> V_33 . V_80 >> 20 ) ,
V_2 -> V_33 . V_38 , V_2 -> V_33 . V_38 / 1024 ,
V_2 -> V_33 . V_85 ) ;
V_50 = F_29 ( & V_2 -> V_33 , NULL , NULL ,
V_68 ? V_68 -> V_86 : NULL ,
V_68 ? V_68 -> V_87 : 0 ) ;
if ( V_50 )
return - V_69 ;
return 0 ;
}
static int F_30 ( struct V_62 * V_14 )
{
struct V_1 * V_2 = F_31 ( V_14 ) ;
return F_32 ( & V_2 -> V_33 ) ;
}
