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
unsigned long div = 0 ;
int V_29 = 0 ;
F_3 ( V_22 , V_2 ) ;
F_3 ( V_24 , V_2 ) ;
div = F_10 ( V_18 , V_19 ) ;
if ( div <= 64 ) {
V_27 . V_30 ( V_22 , V_18 , V_18 ) ;
V_29 = V_27 . V_30 ( V_24 , V_19 , V_19 * div ) ;
} else {
V_27 . V_30 ( V_24 , V_18 , V_18 ) ;
V_29 = V_27 . V_30 ( V_22 , V_19 , V_19 * div ) ;
}
return V_29 ;
}
static struct V_31 * F_15 ( const char * V_32 ,
const char * * V_33 , T_1 V_34 ,
void T_2 * V_35 , T_3 * V_36 , T_4 V_37 ,
unsigned long V_38 ) {
struct V_3 * V_39 ;
struct V_31 * V_31 ;
struct V_40 V_41 ;
T_4 V_42 ;
void T_2 * V_43 , * V_44 ;
V_39 = F_16 ( sizeof( struct V_3 ) , V_45 ) ;
if ( ! V_39 )
return F_17 ( - V_46 ) ;
V_41 . V_32 = V_32 ;
V_41 . V_47 = & V_48 ;
V_41 . V_49 = V_50 | V_51 | V_38 ;
V_41 . V_33 = V_33 ;
V_41 . V_34 = V_34 ;
V_43 = V_35 + 0x18 + ( V_37 & ~ 0x3 ) ;
V_42 = ( V_37 % 4 ) * 0x8 ;
V_44 = V_35 + 0x164 + V_37 * 4 ;
V_39 -> V_13 . V_36 = V_36 ;
V_39 -> V_13 . V_52 = F_18 ( 6 ) - 1 ;
V_39 -> V_13 . V_35 = V_43 ;
V_39 -> V_13 . V_53 = V_42 ;
V_39 -> V_13 . V_54 = NULL ;
V_39 -> V_5 . V_36 = V_36 ;
V_39 -> V_5 . V_35 = V_43 ;
V_39 -> V_5 . V_55 = V_42 + 6 ;
V_39 -> V_23 . V_36 = V_36 ;
V_39 -> V_23 . V_35 = V_35 + 0x58 + V_37 * 4 ;
V_39 -> V_23 . V_56 = 10 ;
V_39 -> V_7 . V_36 = V_36 ;
V_39 -> V_7 . V_35 = V_44 ;
V_39 -> V_7 . V_55 = 6 ;
V_39 -> V_25 . V_36 = V_36 ;
V_39 -> V_25 . V_35 = V_44 ;
V_39 -> V_25 . V_56 = 6 ;
V_39 -> V_2 . V_41 = & V_41 ;
V_31 = F_19 ( NULL , & V_39 -> V_2 ) ;
if ( F_20 ( V_31 ) )
F_21 ( V_39 ) ;
else
F_4 ( L_3 ,
F_22 ( V_31 ) ,
F_22 ( F_23 ( V_31 ) ) ,
( unsigned int ) F_24 ( V_31 ) ) ;
return V_31 ;
}
static const char * * T_5 F_25 ( struct V_57 * V_58 ,
int * V_34 )
{
const char * * V_59 ;
unsigned int V_60 ;
V_60 = F_26 ( V_58 ) ;
if ( F_27 ( ! V_60 ) )
return NULL ;
V_59 = F_28 ( V_60 , sizeof( const char * ) , V_45 ) ;
if ( ! V_59 )
return NULL ;
* V_34 = F_29 ( V_58 , V_59 , V_60 ) ;
return V_59 ;
}
static void T_5 F_30 ( struct V_57 * V_58 )
{
struct V_57 * V_61 ;
void T_2 * V_35 ;
struct V_62 * V_63 ;
const char * * V_59 ;
int V_34 , V_64 ;
T_3 * V_65 = NULL ;
unsigned long V_66 = 0 ;
int V_29 ;
V_61 = F_31 ( V_58 ) ;
if ( ! V_61 )
return;
V_35 = F_32 ( V_61 , 0 ) ;
if ( ! V_35 )
return;
V_59 = F_25 ( V_58 , & V_34 ) ;
if ( ! V_59 )
return;
V_63 = F_16 ( sizeof( * V_63 ) , V_45 ) ;
if ( ! V_63 )
goto V_67;
V_29 = F_33 ( V_58 , L_4 ) ;
if ( V_29 <= 0 ) {
F_34 ( L_5 ,
V_68 , V_63 -> V_69 ) ;
goto V_67;
}
V_63 -> V_69 = V_29 ;
V_63 -> V_70 = F_28 ( V_63 -> V_69 , sizeof( struct V_31 * ) ,
V_45 ) ;
if ( ! V_63 -> V_70 )
goto V_67;
V_65 = F_16 ( sizeof( T_3 ) , V_45 ) ;
if ( ! V_65 )
goto V_67;
F_35 ( V_65 ) ;
for ( V_64 = 0 ; V_64 < V_63 -> V_69 ; V_64 ++ ) {
struct V_31 * V_31 ;
const char * V_71 ;
if ( F_36 ( V_58 , L_4 ,
V_64 , & V_71 ) ) {
break;
}
if ( * V_71 == '\0' )
continue;
V_31 = F_15 ( V_71 , V_59 , V_34 ,
V_35 , V_65 , V_64 , V_66 ) ;
if ( F_20 ( V_31 ) )
goto V_67;
V_63 -> V_70 [ V_64 ] = V_31 ;
}
F_21 ( V_59 ) ;
F_37 ( V_58 , V_72 , V_63 ) ;
return;
V_67:
if ( V_63 )
F_21 ( V_63 -> V_70 ) ;
F_21 ( V_63 ) ;
F_21 ( V_59 ) ;
F_21 ( V_65 ) ;
}
