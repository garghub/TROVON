static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_1 * V_4 = & V_3 -> V_5 . V_2 ;
struct V_1 * V_6 = & V_3 -> V_7 . V_2 ;
V_4 -> V_8 = V_2 -> V_8 ;
V_6 -> V_8 = V_2 -> V_8 ;
V_9 . V_10 ( V_4 ) ;
V_9 . V_10 ( V_6 ) ;
F_3 ( L_1 , F_4 ( V_2 -> V_8 ) ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_1 * V_6 = & V_3 -> V_7 . V_2 ;
V_6 -> V_8 = V_2 -> V_8 ;
V_9 . V_11 ( V_6 ) ;
F_3 ( L_2 , F_4 ( V_2 -> V_8 ) ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_1 * V_6 = & V_3 -> V_7 . V_2 ;
V_6 -> V_8 = V_2 -> V_8 ;
if ( ! V_9 . V_12 ( V_6 ) )
return 0 ;
return 1 ;
}
static T_1 F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_1 * V_13 = & V_3 -> V_14 . V_2 ;
V_13 -> V_8 = V_2 -> V_8 ;
return V_15 . V_16 ( V_13 ) ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_17 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_1 * V_13 = & V_3 -> V_14 . V_2 ;
V_13 -> V_8 = V_2 -> V_8 ;
return V_15 . V_18 ( V_13 , V_17 ) ;
}
static inline unsigned long
F_9 ( unsigned long V_19 , unsigned long V_20 )
{
return V_19 / V_20 + ( ( V_20 > ( 2 * ( V_19 % V_20 ) ) ) ? 0 : 1 ) ;
}
static long F_10 ( struct V_1 * V_2 , unsigned long V_20 ,
unsigned long * V_21 )
{
unsigned long div ;
div = F_9 ( * V_21 , V_20 ) ;
if ( F_11 ( V_2 -> V_8 ) & V_22 ) {
* V_21 = V_20 * div ;
return V_20 ;
}
return * V_21 / div ;
}
unsigned long F_12 ( struct V_1 * V_2 ,
unsigned long V_19 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_1 * V_23 = & V_3 -> V_24 . V_2 ;
struct V_1 * V_25 = & V_3 -> V_26 . V_2 ;
unsigned long V_27 ;
V_23 -> V_8 = V_2 -> V_8 ;
V_25 -> V_8 = V_2 -> V_8 ;
V_27 = V_28 . V_29 ( V_23 , V_19 ) ;
return V_28 . V_29 ( V_25 , V_27 ) ;
}
static int F_13 ( struct V_1 * V_2 , unsigned long V_20 ,
unsigned long V_19 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_1 * V_23 = & V_3 -> V_24 . V_2 ;
struct V_1 * V_25 = & V_3 -> V_26 . V_2 ;
unsigned long V_30 = 0 ;
int V_31 = 0 ;
V_23 -> V_8 = V_2 -> V_8 ;
V_25 -> V_8 = V_2 -> V_8 ;
V_30 = F_9 ( V_19 , V_20 ) ;
V_28 . V_32 ( V_25 , V_19 , V_19 ) ;
V_31 = V_28 . V_32 ( V_23 , V_20 , V_20 * V_30 ) ;
return V_31 ;
}
struct V_8 * F_14 ( const char * V_33 ,
const char * * V_34 , T_1 V_35 ,
void T_2 * V_36 , T_3 * V_37 , T_4 V_38 ,
unsigned long V_39 ) {
struct V_3 * V_40 ;
struct V_8 * V_8 ;
struct V_41 V_42 ;
T_4 V_43 ;
void T_2 * V_44 , * V_45 ;
V_40 = F_15 ( sizeof( struct V_3 ) , V_46 ) ;
if ( ! V_40 )
return F_16 ( - V_47 ) ;
V_42 . V_33 = V_33 ;
V_42 . V_48 = & V_49 ;
V_42 . V_50 = V_51 | V_39 ;
V_42 . V_34 = V_34 ;
V_42 . V_35 = V_35 ;
V_44 = V_36 + 0x18 + ( V_38 & ~ 0x3 ) ;
V_43 = ( V_38 % 4 ) * 0x8 ;
V_45 = V_36 + 0x164 + V_38 * 4 ;
V_40 -> V_14 . V_37 = V_37 ;
V_40 -> V_14 . V_52 = F_17 ( 6 ) - 1 ;
V_40 -> V_14 . V_36 = V_44 ;
V_40 -> V_14 . V_53 = V_43 ;
V_40 -> V_14 . V_54 = NULL ;
V_40 -> V_5 . V_37 = V_37 ;
V_40 -> V_5 . V_36 = V_44 ;
V_40 -> V_5 . V_55 = V_43 + 6 ;
V_40 -> V_24 . V_37 = V_37 ;
V_40 -> V_24 . V_36 = V_36 + 0x58 + V_38 * 4 ;
V_40 -> V_24 . V_56 = 10 ;
V_40 -> V_7 . V_37 = V_37 ;
V_40 -> V_7 . V_36 = V_45 ;
V_40 -> V_7 . V_55 = 6 ;
V_40 -> V_26 . V_37 = V_37 ;
V_40 -> V_26 . V_36 = V_45 ;
V_40 -> V_26 . V_56 = 6 ;
V_40 -> V_2 . V_42 = & V_42 ;
V_8 = F_18 ( NULL , & V_40 -> V_2 ) ;
if ( F_19 ( V_8 ) )
F_20 ( V_40 ) ;
else
F_3 ( L_3 ,
F_4 ( V_8 ) ,
F_4 ( F_21 ( V_8 ) ) ,
( unsigned int ) F_22 ( V_8 ) ) ;
return V_8 ;
}
static const char * * T_5 F_23 ( struct V_57 * V_58 ,
int * V_35 )
{
const char * * V_59 ;
int V_60 , V_61 ;
V_60 = F_24 ( V_58 , L_4 , L_5 ) ;
if ( F_25 ( V_60 <= 0 ) )
return NULL ;
V_59 = F_26 ( V_60 , sizeof( const char * ) , V_46 ) ;
if ( ! V_59 )
return NULL ;
for ( V_61 = 0 ; V_61 < V_60 ; V_61 ++ )
V_59 [ V_61 ] = F_27 ( V_58 , V_61 ) ;
* V_35 = V_60 ;
return V_59 ;
}
void T_5 F_28 ( struct V_57 * V_58 )
{
struct V_57 * V_62 ;
void T_2 * V_36 ;
struct V_63 * V_64 ;
const char * * V_59 ;
int V_35 , V_61 ;
T_3 * V_65 = NULL ;
unsigned long V_66 = 0 ;
V_62 = F_29 ( V_58 ) ;
if ( ! V_62 )
return;
V_36 = F_30 ( V_62 , 0 ) ;
if ( ! V_36 )
return;
V_59 = F_23 ( V_58 , & V_35 ) ;
if ( ! V_59 )
return;
V_64 = F_15 ( sizeof( * V_64 ) , V_46 ) ;
if ( ! V_64 )
goto V_67;
V_64 -> V_68 = F_31 ( V_58 ,
L_6 ) ;
if ( V_64 -> V_68 <= 0 ) {
F_32 ( L_7 ,
V_69 , V_64 -> V_68 ) ;
goto V_67;
}
V_64 -> V_70 = F_26 ( V_64 -> V_68 , sizeof( struct V_8 * ) ,
V_46 ) ;
if ( ! V_64 -> V_70 )
goto V_67;
V_65 = F_15 ( sizeof( T_3 ) , V_46 ) ;
if ( ! V_65 )
goto V_67;
for ( V_61 = 0 ; V_61 < V_64 -> V_68 ; V_61 ++ ) {
struct V_8 * V_8 ;
const char * V_71 ;
if ( F_33 ( V_58 , L_6 ,
V_61 , & V_71 ) ) {
break;
}
if ( * V_71 == '\0' )
continue;
V_8 = F_14 ( V_71 , V_59 , V_35 ,
V_36 , V_65 , V_61 , V_66 ) ;
if ( F_19 ( V_8 ) )
goto V_67;
V_64 -> V_70 [ V_61 ] = V_8 ;
}
F_20 ( V_59 ) ;
F_34 ( V_58 , V_72 , V_64 ) ;
return;
V_67:
if ( V_64 )
F_20 ( V_64 -> V_70 ) ;
F_20 ( V_64 ) ;
F_20 ( V_59 ) ;
F_20 ( V_65 ) ;
}
