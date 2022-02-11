static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 = F_3 ( V_4 , V_6 ) ;
return ! ! V_5 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_7 = F_3 ( V_4 , V_8 ) ;
return ! V_7 ;
}
unsigned long F_5 ( struct V_1 * V_2 ,
unsigned long V_9 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_10 , V_11 , V_12 ;
unsigned long V_13 ;
T_2 V_14 ;
if ( ! F_4 ( V_2 ) || ! F_1 ( V_2 ) )
return 0 ;
V_12 = F_3 ( V_4 , V_12 ) ;
V_10 = F_3 ( V_4 , V_10 ) ;
V_11 = F_3 ( V_4 , V_11 ) ;
if ( ! V_10 )
V_10 ++ ;
V_14 = ( T_2 ) 2 * ( T_2 ) V_9 * ( T_2 ) V_11 ;
V_13 = ( unsigned long ) F_6 ( V_14 , V_10 * ( 1 << V_12 ) ) ;
F_7 ( L_1 , F_8 ( V_2 -> V_15 ) , V_16 , V_13 ) ;
return V_13 ;
}
unsigned long F_9 ( struct V_1 * V_2 ,
unsigned long V_9 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_10 , V_11 ;
unsigned long V_13 ;
if ( ! F_4 ( V_2 ) || ! F_1 ( V_2 ) )
return 0 ;
V_10 = F_3 ( V_4 , V_10 ) ;
V_11 = F_3 ( V_4 , V_11 ) ;
if ( ! V_10 )
V_10 = 1 ;
V_13 = ( ( 2 * ( V_9 / 1000 ) * V_11 ) / V_10 ) * 1000 ;
F_7 ( L_1 , F_8 ( V_2 -> V_15 ) , V_16 , V_13 ) ;
return V_13 ;
}
unsigned long F_10 ( struct V_1 * V_2 ,
unsigned long V_9 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_11 , V_17 ;
unsigned long V_13 = 0 ;
if ( ! F_4 ( V_2 ) || ! F_1 ( V_2 ) )
return 0 ;
V_11 = F_3 ( V_4 , V_11 ) ;
V_17 = F_3 ( V_4 , V_17 ) ;
if ( V_17 )
V_13 = ( ( 2 * ( V_9 / 1000 ) * V_11 ) / V_17 ) * 1000 ;
F_7 ( L_1 , F_8 ( V_2 -> V_15 ) , V_16 , V_13 ) ;
return V_13 ;
}
unsigned long F_11 ( struct V_1 * V_2 ,
unsigned long V_9 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_18 , V_19 , V_17 ;
unsigned long V_13 ;
if ( ! F_4 ( V_2 ) || ! F_1 ( V_2 ) )
return 0 ;
V_18 = F_3 ( V_4 , V_18 [ 0 ] ) ;
V_19 = F_3 ( V_4 , V_19 ) ;
V_17 = F_3 ( V_4 , V_17 ) ;
if ( ! V_17 )
V_17 = 1 ;
if ( ! V_18 )
V_18 = 1 ;
V_13 = ( ( ( V_9 / 1000 ) * V_19 ) / ( V_18 * V_17 ) ) * 1000 ;
F_7 ( L_1 , F_8 ( V_2 -> V_15 ) , V_16 , V_13 ) ;
return V_13 ;
}
static struct V_15 * T_3 F_12 ( const char * V_20 ,
struct V_21 * V_22 ,
void T_4 * V_23 ,
const char * V_24 )
{
struct V_3 * V_4 ;
struct V_15 * V_15 ;
struct V_25 V_26 ;
V_4 = F_13 ( sizeof( * V_4 ) , V_27 ) ;
if ( ! V_4 )
return F_14 ( - V_28 ) ;
V_26 . V_29 = V_24 ;
V_26 . V_30 = V_22 -> V_30 ;
V_26 . V_31 = V_32 ;
V_26 . V_33 = & V_20 ;
V_26 . V_34 = 1 ;
V_4 -> V_35 = V_22 ;
V_4 -> V_36 = V_23 ;
V_4 -> V_2 . V_26 = & V_26 ;
V_15 = F_15 ( NULL , & V_4 -> V_2 ) ;
if ( F_16 ( V_15 ) ) {
F_17 ( V_4 ) ;
return V_15 ;
}
F_7 ( L_2 ,
F_8 ( V_15 ) ,
F_8 ( F_18 ( V_15 ) ) ,
F_19 ( V_15 ) ) ;
return V_15 ;
}
static struct V_15 * T_3 F_20 ( const char * V_20 ,
const char * V_24 )
{
struct V_15 * V_15 ;
V_15 = F_21 ( NULL , V_24 , V_20 , 0 , 1 , 2 ) ;
if ( F_16 ( V_15 ) )
return V_15 ;
F_7 ( L_2 ,
F_8 ( V_15 ) ,
F_8 ( F_18 ( V_15 ) ) ,
F_19 ( V_15 ) ) ;
return V_15 ;
}
static void T_4 * T_3 F_22 (
struct V_37 * V_38 )
{
struct V_37 * V_39 ;
void T_4 * V_23 = NULL ;
V_39 = F_23 ( V_38 ) ;
if ( ! V_39 )
return NULL ;
V_23 = F_24 ( V_39 , 0 ) ;
F_25 ( V_39 ) ;
return V_23 ;
}
static void T_3 F_26 ( struct V_37 * V_38 )
{
const int V_40 = 3 ;
struct V_41 * V_42 ;
const char * V_20 ;
void T_4 * V_23 ;
const char * V_24 ;
V_20 = F_27 ( V_38 , 0 ) ;
if ( ! V_20 )
return;
V_23 = F_22 ( V_38 ) ;
if ( ! V_23 )
return;
V_42 = F_13 ( sizeof( * V_42 ) , V_27 ) ;
if ( ! V_42 )
return;
V_42 -> V_43 = V_40 ;
V_42 -> V_44 = F_13 ( V_42 -> V_43 * sizeof( struct V_15 * ) ,
V_27 ) ;
if ( ! V_42 -> V_44 )
goto V_45;
if ( F_28 ( V_38 , L_3 ,
0 , & V_24 ) )
goto V_45;
V_42 -> V_44 [ 0 ] = F_12 ( V_20 ,
& V_46 ,
V_23 + V_47 ,
V_24 ) ;
if ( F_16 ( V_42 -> V_44 [ 0 ] ) )
goto V_45;
if ( F_28 ( V_38 , L_3 ,
1 , & V_24 ) )
goto V_45;
V_42 -> V_44 [ 1 ] = F_20 ( F_8
( V_42 -> V_44 [ 0 ] ) ,
V_24 ) ;
if ( F_16 ( V_42 -> V_44 [ 1 ] ) )
goto V_45;
if ( F_28 ( V_38 , L_3 ,
2 , & V_24 ) )
goto V_45;
V_42 -> V_44 [ 2 ] = F_12 ( V_20 ,
& V_48 ,
V_23 + V_49 ,
V_24 ) ;
if ( F_16 ( V_42 -> V_44 [ 2 ] ) )
goto V_45;
F_29 ( V_38 , V_50 , V_42 ) ;
return;
V_45:
F_17 ( V_42 -> V_44 ) ;
F_17 ( V_42 ) ;
}
static struct V_15 * T_3 F_30 ( const char * V_20 ,
void * T_4 V_23 ,
struct V_21 * V_22 ,
int V_18 ,
T_5 * V_51 ,
const char * V_52 )
{
struct V_15 * V_15 ;
unsigned long V_31 ;
struct V_53 * V_54 ;
struct V_55 * div ;
V_31 = V_56 | V_57 ;
V_54 = F_13 ( sizeof( * V_54 ) , V_27 ) ;
if ( ! V_54 )
return F_14 ( - V_28 ) ;
V_54 -> V_31 = V_58 ;
V_54 -> V_23 = V_23 + V_22 -> V_59 [ V_18 ] . V_60 ;
V_54 -> V_61 = V_22 -> V_59 [ V_18 ] . V_62 ;
V_54 -> V_63 = V_51 ;
div = F_13 ( sizeof( * div ) , V_27 ) ;
if ( ! div ) {
F_17 ( V_54 ) ;
return F_14 ( - V_28 ) ;
}
div -> V_31 = V_64 | V_65 ;
div -> V_23 = V_23 + V_22 -> V_18 [ V_18 ] . V_60 ;
div -> V_62 = V_22 -> V_18 [ V_18 ] . V_62 ;
div -> V_66 = F_31 ( V_22 -> V_18 [ V_18 ] . V_67 ) ;
div -> V_63 = V_51 ;
V_15 = F_32 ( NULL , V_52 , & V_20 , 1 ,
NULL , NULL ,
& div -> V_2 , & V_68 ,
& V_54 -> V_2 , & V_69 ,
V_31 ) ;
if ( F_16 ( V_15 ) )
return V_15 ;
F_7 ( L_2 ,
F_8 ( V_15 ) ,
F_8 ( F_18 ( V_15 ) ) ,
F_19 ( V_15 ) ) ;
return V_15 ;
}
static void T_3 F_33 ( struct V_37 * V_38 )
{
const struct V_70 * V_71 ;
struct V_15 * V_15 ;
const char * V_20 , * V_72 ;
void T_4 * V_73 ;
int V_74 , V_18 ;
struct V_41 * V_42 ;
struct V_21 * V_35 ;
V_71 = F_34 ( V_75 , V_38 ) ;
if ( ! V_71 ) {
F_35 ( L_4 , V_16 ) ;
return;
}
V_35 = (struct V_21 * ) V_71 -> V_35 ;
V_20 = F_27 ( V_38 , 0 ) ;
if ( ! V_20 )
return;
V_73 = F_22 ( V_38 ) ;
if ( ! V_73 )
return;
V_15 = F_12 ( V_20 , V_35 , V_73 , V_38 -> V_29 ) ;
if ( F_16 ( V_15 ) )
return;
V_72 = F_8 ( V_15 ) ;
V_74 = V_35 -> V_74 ;
V_42 = F_13 ( sizeof( * V_42 ) , V_27 ) ;
if ( ! V_42 )
return;
V_42 -> V_43 = V_74 ;
V_42 -> V_44 = F_13 ( V_42 -> V_43 * sizeof( struct V_15 * ) ,
V_27 ) ;
if ( ! V_42 -> V_44 )
goto V_45;
for ( V_18 = 0 ; V_18 < V_74 ; V_18 ++ ) {
struct V_15 * V_15 ;
const char * V_24 ;
if ( F_28 ( V_38 , L_3 ,
V_18 , & V_24 ) )
return;
V_15 = F_30 ( V_72 , V_73 , V_35 ,
V_18 , & V_76 , V_24 ) ;
if ( F_16 ( V_15 ) )
goto V_45;
V_42 -> V_44 [ V_18 ] = V_15 ;
}
F_29 ( V_38 , V_50 , V_42 ) ;
return;
V_45:
F_17 ( V_72 ) ;
F_17 ( V_42 -> V_44 ) ;
F_17 ( V_42 ) ;
}
static void T_3 F_36 ( struct V_37 * V_38 )
{
const struct V_70 * V_71 ;
struct V_15 * V_15 ;
const char * V_20 ;
void T_4 * V_23 ;
const char * V_24 ;
struct V_21 * V_35 ;
V_71 = F_34 ( V_77 , V_38 ) ;
if ( ! V_71 ) {
F_35 ( L_4 , V_16 ) ;
return;
}
V_35 = (struct V_21 * ) V_71 -> V_35 ;
V_20 = F_27 ( V_38 , 0 ) ;
if ( ! V_20 )
return;
V_23 = F_22 ( V_38 ) ;
if ( ! V_23 )
return;
if ( F_28 ( V_38 , L_3 ,
0 , & V_24 ) )
return;
V_15 = F_12 ( V_20 , V_35 , V_23 , V_24 ) ;
if ( ! F_16 ( V_15 ) )
F_29 ( V_38 , V_78 , V_15 ) ;
return;
}
