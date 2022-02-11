static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_1 * V_4 = & V_3 -> V_5 . V_2 ;
struct V_1 * V_6 = & V_3 -> V_7 . V_2 ;
F_3 ( V_4 , V_2 ) ;
F_3 ( V_6 , V_2 ) ;
V_8 . V_9 ( V_4 ) ;
V_8 . V_9 ( V_6 ) ;
F_4 ( L_1 , F_5 ( V_2 ) ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_1 * V_6 = & V_3 -> V_7 . V_2 ;
F_3 ( V_6 , V_2 ) ;
V_8 . V_10 ( V_6 ) ;
F_4 ( L_2 , F_5 ( V_2 ) ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_1 * V_6 = & V_3 -> V_7 . V_2 ;
F_3 ( V_6 , V_2 ) ;
if ( ! V_8 . V_11 ( V_6 ) )
return 0 ;
return 1 ;
}
static T_1 F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_1 * V_12 = & V_3 -> V_13 . V_2 ;
F_3 ( V_12 , V_2 ) ;
return V_14 . V_15 ( V_12 ) ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_16 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_1 * V_12 = & V_3 -> V_13 . V_2 ;
F_3 ( V_12 , V_2 ) ;
return V_14 . V_17 ( V_12 , V_16 ) ;
}
static inline unsigned long
F_10 ( unsigned long V_18 , unsigned long V_19 )
{
return V_18 / V_19 + ( ( V_19 > ( 2 * ( V_18 % V_19 ) ) ) ? 0 : 1 ) ;
}
static long F_11 ( struct V_1 * V_2 , unsigned long V_19 ,
unsigned long * V_20 )
{
unsigned long div ;
div = F_10 ( * V_20 , V_19 ) ;
if ( F_12 ( V_2 ) & V_21 ) {
* V_20 = V_19 * div ;
return V_19 ;
}
return * V_20 / div ;
}
static unsigned long F_13 ( struct V_1 * V_2 ,
unsigned long V_18 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_1 * V_22 = & V_3 -> V_23 . V_2 ;
struct V_1 * V_24 = & V_3 -> V_25 . V_2 ;
unsigned long V_26 ;
F_3 ( V_22 , V_2 ) ;
F_3 ( V_24 , V_2 ) ;
V_26 = V_27 . V_28 ( V_22 , V_18 ) ;
return V_27 . V_28 ( V_24 , V_26 ) ;
}
static int F_14 ( struct V_1 * V_2 , unsigned long V_19 ,
unsigned long V_18 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_1 * V_22 = & V_3 -> V_23 . V_2 ;
struct V_1 * V_24 = & V_3 -> V_25 . V_2 ;
struct V_1 * V_29 = & V_3 -> V_30 . V_2 ;
struct V_31 * V_32 = F_15 ( V_29 ) ;
unsigned long div = 0 ;
int V_33 = 0 ;
T_2 V_34 ;
F_3 ( V_22 , V_2 ) ;
F_3 ( V_24 , V_2 ) ;
if ( V_3 -> V_35 ) {
V_34 = F_16 ( V_32 -> V_34 ) ;
V_34 &= ~ F_17 ( V_32 -> V_36 ) ;
F_18 ( V_34 , V_32 -> V_34 ) ;
}
div = F_10 ( V_18 , V_19 ) ;
if ( div <= 64 ) {
V_27 . V_37 ( V_22 , V_18 , V_18 ) ;
V_33 = V_27 . V_37 ( V_24 , V_19 , V_19 * div ) ;
} else {
V_27 . V_37 ( V_24 , V_18 , V_18 ) ;
V_33 = V_27 . V_37 ( V_22 , V_19 , V_19 * div ) ;
}
return V_33 ;
}
static struct V_38 * F_19 ( const char * V_39 ,
const char * * V_40 , T_1 V_41 ,
void T_3 * V_34 , T_4 * V_42 , T_2 V_43 ,
unsigned long V_44 , bool V_45 ) {
struct V_3 * V_46 ;
struct V_38 * V_38 ;
struct V_47 V_48 ;
T_2 V_49 ;
void T_3 * V_50 , * V_51 ;
V_46 = F_20 ( sizeof( struct V_3 ) , V_52 ) ;
if ( ! V_46 )
return F_21 ( - V_53 ) ;
V_48 . V_39 = V_39 ;
V_48 . V_54 = & V_55 ;
V_48 . V_56 = V_57 | V_58 | V_44 ;
V_48 . V_40 = V_40 ;
V_48 . V_41 = V_41 ;
V_50 = V_34 + 0x18 + ( V_43 & ~ 0x3 ) ;
V_49 = ( V_43 % 4 ) * 0x8 ;
V_51 = V_34 + 0x164 + V_43 * 4 ;
V_46 -> V_13 . V_42 = V_42 ;
V_46 -> V_13 . V_59 = F_17 ( 6 ) - 1 ;
V_46 -> V_13 . V_34 = V_50 ;
V_46 -> V_13 . V_60 = V_49 ;
V_46 -> V_13 . V_61 = NULL ;
V_46 -> V_5 . V_42 = V_42 ;
V_46 -> V_5 . V_34 = V_50 ;
V_46 -> V_5 . V_36 = V_49 + 6 ;
V_46 -> V_23 . V_42 = V_42 ;
V_46 -> V_23 . V_34 = V_34 + 0x58 + V_43 * 4 ;
V_46 -> V_23 . V_62 = 10 ;
V_46 -> V_7 . V_42 = V_42 ;
V_46 -> V_7 . V_34 = V_51 ;
V_46 -> V_7 . V_36 = 6 ;
V_46 -> V_25 . V_42 = V_42 ;
V_46 -> V_25 . V_34 = V_51 ;
V_46 -> V_25 . V_62 = 6 ;
V_46 -> V_30 . V_42 = V_42 ;
V_46 -> V_30 . V_34 = V_51 ;
V_46 -> V_30 . V_36 = 7 ;
V_46 -> V_35 = V_45 ;
V_46 -> V_2 . V_48 = & V_48 ;
V_38 = F_22 ( NULL , & V_46 -> V_2 ) ;
if ( F_23 ( V_38 ) )
F_24 ( V_46 ) ;
else
F_4 ( L_3 ,
F_25 ( V_38 ) ,
F_25 ( F_26 ( V_38 ) ) ,
( unsigned int ) F_27 ( V_38 ) ) ;
return V_38 ;
}
static const char * * T_5 F_28 ( struct V_63 * V_64 ,
int * V_41 )
{
const char * * V_65 ;
unsigned int V_66 ;
V_66 = F_29 ( V_64 ) ;
if ( F_30 ( ! V_66 ) )
return NULL ;
V_65 = F_31 ( V_66 , sizeof( const char * ) , V_52 ) ;
if ( ! V_65 )
return NULL ;
* V_41 = F_32 ( V_64 , V_65 , V_66 ) ;
return V_65 ;
}
static void T_5 F_33 ( struct V_63 * V_64 )
{
struct V_63 * V_67 ;
void T_3 * V_34 ;
struct V_68 * V_69 ;
const char * * V_65 ;
int V_41 , V_70 ;
T_4 * V_71 = NULL ;
const struct V_72 * V_73 ;
struct V_74 * V_75 = NULL ;
unsigned long V_76 = 0 ;
int V_33 ;
bool V_77 = 0 ;
V_67 = F_34 ( V_64 ) ;
if ( ! V_67 )
return;
V_34 = F_35 ( V_67 , 0 ) ;
if ( ! V_34 )
return;
V_65 = F_28 ( V_64 , & V_41 ) ;
if ( ! V_65 )
return;
V_73 = F_36 ( V_78 , V_64 ) ;
if ( V_73 ) {
V_75 = (struct V_74 * ) V_73 -> V_75 ;
V_76 = V_75 -> V_56 ;
V_77 = V_75 -> V_45 ;
}
V_69 = F_20 ( sizeof( * V_69 ) , V_52 ) ;
if ( ! V_69 )
goto V_79;
V_33 = F_37 ( V_64 , L_4 ) ;
if ( V_33 <= 0 ) {
F_38 ( L_5 ,
V_80 , V_69 -> V_81 ) ;
goto V_79;
}
V_69 -> V_81 = V_33 ;
V_69 -> V_82 = F_31 ( V_69 -> V_81 , sizeof( struct V_38 * ) ,
V_52 ) ;
if ( ! V_69 -> V_82 )
goto V_79;
V_71 = F_20 ( sizeof( T_4 ) , V_52 ) ;
if ( ! V_71 )
goto V_79;
F_39 ( V_71 ) ;
for ( V_70 = 0 ; V_70 < V_69 -> V_81 ; V_70 ++ ) {
struct V_38 * V_38 ;
const char * V_83 ;
if ( F_40 ( V_64 , L_4 ,
V_70 , & V_83 ) ) {
break;
}
F_41 ( V_64 , V_70 , & V_76 ) ;
if ( * V_83 == '\0' )
continue;
V_38 = F_19 ( V_83 , V_65 , V_41 ,
V_34 , V_71 , V_70 , V_76 , V_77 ) ;
if ( F_23 ( V_38 ) )
goto V_79;
V_69 -> V_82 [ V_70 ] = V_38 ;
}
F_24 ( V_65 ) ;
F_42 ( V_64 , V_84 , V_69 ) ;
return;
V_79:
if ( V_69 )
F_24 ( V_69 -> V_82 ) ;
F_24 ( V_69 ) ;
F_24 ( V_65 ) ;
F_24 ( V_71 ) ;
}
