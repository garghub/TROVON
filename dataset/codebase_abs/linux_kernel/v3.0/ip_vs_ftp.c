static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_4 -> V_5 |= V_6 ;
return 0 ;
}
static int
F_2 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return 0 ;
}
static int F_3 ( char * V_7 , char * V_8 ,
const char * V_9 , T_1 V_10 , char V_11 ,
T_2 * V_12 , T_3 * V_13 ,
char * * V_14 , char * * V_15 )
{
unsigned char V_16 [ 6 ] ;
int V_17 = 0 ;
if ( V_8 - V_7 < V_10 ) {
if ( F_4 ( V_7 , V_9 , V_8 - V_7 ) == 0 )
return - 1 ;
else
return 0 ;
}
if ( F_4 ( V_7 , V_9 , V_10 ) != 0 ) {
return 0 ;
}
* V_14 = V_7 + V_10 ;
for ( V_7 = * V_14 ; * V_7 != V_11 ; V_7 ++ ) {
if ( V_7 == V_8 )
return - 1 ;
}
* V_15 = V_7 ;
memset ( V_16 , 0 , sizeof( V_16 ) ) ;
for ( V_7 = * V_14 ; V_7 != * V_15 ; V_7 ++ ) {
if ( * V_7 >= '0' && * V_7 <= '9' ) {
V_16 [ V_17 ] = V_16 [ V_17 ] * 10 + * V_7 - '0' ;
} else if ( * V_7 == ',' && V_17 < 5 ) {
V_17 ++ ;
} else {
return - 1 ;
}
}
if ( V_17 != 5 )
return - 1 ;
* V_12 = F_5 ( ( T_2 * ) V_16 ) ;
* V_13 = F_5 ( ( T_3 * ) ( V_16 + 4 ) ) ;
return 1 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_18 * V_19 , int * V_20 )
{
struct V_21 * V_22 ;
struct V_23 * V_24 ;
char * V_7 , * V_8 ;
char * V_14 , * V_15 ;
union V_25 V_26 ;
T_3 V_13 ;
struct V_3 * V_27 ;
char V_28 [ 24 ] ;
unsigned V_29 ;
int V_30 = 0 ;
enum V_31 V_32 ;
struct V_33 * V_34 ;
struct V_35 * V_35 ;
#ifdef F_7
if ( V_4 -> V_36 == V_37 )
return 1 ;
#endif
* V_20 = 0 ;
if ( V_4 -> V_38 != V_39 )
return 1 ;
if ( ! F_8 ( V_19 , V_19 -> V_40 ) )
return 0 ;
if ( V_4 -> V_41 == & V_42 ) {
V_22 = F_9 ( V_19 ) ;
V_24 = (struct V_23 * ) & ( ( ( char * ) V_22 ) [ V_22 -> V_43 * 4 ] ) ;
V_7 = ( char * ) V_24 + ( V_24 -> V_44 << 2 ) ;
V_8 = F_10 ( V_19 ) ;
if ( F_3 ( V_7 , V_8 ,
V_45 ,
sizeof( V_45 ) - 1 , ')' ,
& V_26 . V_46 , & V_13 ,
& V_14 , & V_15 ) != 1 )
return 1 ;
F_11 ( 7 , L_1 ,
& V_26 . V_46 , F_12 ( V_13 ) , & V_4 -> V_47 . V_46 , 0 ) ;
{
struct V_48 V_16 ;
F_13 ( F_14 ( V_4 ) , V_49 ,
V_22 -> V_50 , & V_26 , V_13 ,
& V_4 -> V_47 , 0 , & V_16 ) ;
V_27 = F_15 ( & V_16 ) ;
}
if ( ! V_27 ) {
struct V_48 V_16 ;
F_13 ( F_14 ( V_4 ) ,
V_49 , V_51 , & V_4 -> V_47 ,
0 , & V_4 -> V_52 , V_13 , & V_16 ) ;
V_27 = F_16 ( & V_16 , & V_26 , V_13 ,
V_53 |
V_6 ,
V_4 -> V_54 , V_19 -> V_55 ) ;
if ( ! V_27 )
return 0 ;
F_17 ( V_27 , V_4 ) ;
}
V_26 . V_46 = V_27 -> V_52 . V_46 ;
V_13 = V_27 -> V_56 ;
snprintf ( V_28 , sizeof( V_28 ) , L_2 ,
( ( unsigned char * ) & V_26 . V_46 ) [ 0 ] ,
( ( unsigned char * ) & V_26 . V_46 ) [ 1 ] ,
( ( unsigned char * ) & V_26 . V_46 ) [ 2 ] ,
( ( unsigned char * ) & V_26 . V_46 ) [ 3 ] ,
F_12 ( V_13 ) >> 8 ,
F_12 ( V_13 ) & 0xFF ) ;
V_29 = strlen ( V_28 ) ;
V_34 = F_18 ( V_19 , & V_32 ) ;
if ( V_34 && ! F_19 ( V_34 ) && F_20 ( V_34 ) ) {
V_30 = F_21 ( V_19 , V_34 , V_32 ,
V_14 - V_7 , V_15 - V_14 ,
V_28 , V_29 ) ;
if ( V_30 ) {
F_22 ( V_19 , V_34 , V_27 ,
V_51 , 0 , 0 ) ;
if ( V_19 -> V_57 == V_58 )
V_19 -> V_57 = V_59 ;
V_30 = 1 ;
}
}
V_35 = F_23 ( V_19 ) ;
V_4 -> V_41 = NULL ;
F_24 ( V_35 , V_27 ) ;
F_25 ( V_27 ) ;
return V_30 ;
}
return 1 ;
}
static int F_26 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_18 * V_19 , int * V_20 )
{
struct V_21 * V_22 ;
struct V_23 * V_24 ;
char * V_7 , * V_60 , * V_8 ;
char * V_14 , * V_15 ;
union V_25 V_61 ;
T_3 V_13 ;
struct V_3 * V_27 ;
struct V_35 * V_35 ;
#ifdef F_7
if ( V_4 -> V_36 == V_37 )
return 1 ;
#endif
* V_20 = 0 ;
if ( V_4 -> V_38 != V_39 )
return 1 ;
if ( ! F_8 ( V_19 , V_19 -> V_40 ) )
return 0 ;
V_22 = F_9 ( V_19 ) ;
V_24 = (struct V_23 * ) & ( ( ( char * ) V_22 ) [ V_22 -> V_43 * 4 ] ) ;
V_7 = V_60 = ( char * ) V_24 + ( V_24 -> V_44 << 2 ) ;
V_8 = F_10 ( V_19 ) ;
while ( V_7 <= V_8 - 6 ) {
if ( F_4 ( V_7 , L_3 , 6 ) == 0 ) {
F_11 ( 7 , L_4 ,
V_7 - V_60 ,
V_8 - V_60 ) ;
V_4 -> V_41 = & V_42 ;
return 1 ;
}
V_7 ++ ;
}
if ( F_3 ( V_60 , V_8 ,
V_62 , sizeof( V_62 ) - 1 ,
'\r' , & V_61 . V_46 , & V_13 ,
& V_14 , & V_15 ) != 1 )
return 1 ;
F_11 ( 7 , L_5 , & V_61 . V_46 , F_12 ( V_13 ) ) ;
V_4 -> V_41 = NULL ;
F_11 ( 7 , L_6 ,
F_27 ( V_22 -> V_50 ) ,
& V_61 . V_46 , F_12 ( V_13 ) , & V_4 -> V_52 . V_46 , 0 ) ;
{
struct V_48 V_16 ;
F_13 ( F_14 ( V_4 ) , V_49 ,
V_22 -> V_50 , & V_61 , V_13 , & V_4 -> V_52 ,
F_28 ( F_12 ( V_4 -> V_56 ) - 1 ) , & V_16 ) ;
V_27 = F_29 ( & V_16 ) ;
if ( ! V_27 ) {
V_27 = F_16 ( & V_16 , & V_4 -> V_63 ,
F_28 ( F_12 ( V_4 -> V_64 ) - 1 ) ,
V_6 , V_4 -> V_54 ,
V_19 -> V_55 ) ;
if ( ! V_27 )
return 0 ;
F_17 ( V_27 , V_4 ) ;
}
}
V_35 = F_23 ( V_19 ) ;
F_24 ( V_35 , V_27 ) ;
F_25 ( V_27 ) ;
return 1 ;
}
static int T_4 F_30 ( struct V_35 * V_35 )
{
int V_17 , V_30 ;
struct V_1 * V_2 ;
struct V_65 * V_66 = F_31 ( V_35 ) ;
V_2 = F_32 ( & V_67 , sizeof( struct V_1 ) , V_68 ) ;
if ( ! V_2 )
return - V_69 ;
F_33 ( & V_2 -> V_70 ) ;
F_33 ( & V_2 -> V_71 ) ;
V_66 -> V_72 = V_2 ;
V_30 = F_34 ( V_35 , V_2 ) ;
if ( V_30 )
goto V_73;
for ( V_17 = 0 ; V_17 < V_74 ; V_17 ++ ) {
if ( ! V_75 [ V_17 ] )
continue;
V_30 = F_35 ( V_35 , V_2 , V_2 -> V_50 , V_75 [ V_17 ] ) ;
if ( V_30 )
goto V_76;
F_36 ( L_7 ,
V_2 -> V_77 , V_17 , V_75 [ V_17 ] ) ;
}
return 0 ;
V_76:
F_37 ( V_35 , V_2 ) ;
V_73:
F_38 ( V_66 -> V_72 ) ;
return V_30 ;
}
static void F_39 ( struct V_35 * V_35 )
{
struct V_65 * V_66 = F_31 ( V_35 ) ;
F_37 ( V_35 , V_66 -> V_72 ) ;
F_38 ( V_66 -> V_72 ) ;
}
int T_5 F_40 ( void )
{
int V_78 ;
V_78 = F_41 ( & V_79 ) ;
return V_78 ;
}
static void T_6 F_42 ( void )
{
F_43 ( & V_79 ) ;
}
