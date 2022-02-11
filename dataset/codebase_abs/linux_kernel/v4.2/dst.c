static void F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
int V_4 = 0 ;
unsigned long V_5 = ~ 0L ;
struct V_6 * V_7 , * V_8 , V_9 ;
struct V_6 * V_10 = & V_9 ;
F_2 ( & V_11 ) ;
V_8 = V_12 ;
V_13:
while ( ( V_7 = V_8 ) != NULL ) {
V_8 = V_7 -> V_8 ;
F_3 ( & V_8 -> V_8 ) ;
F_4 () ;
if ( F_5 ( F_6 ( & V_7 -> V_14 ) ) ) {
V_10 -> V_8 = V_7 ;
V_10 = V_7 ;
V_3 ++ ;
continue;
}
V_4 ++ ;
V_7 = F_7 ( V_7 ) ;
if ( V_7 ) {
if ( V_7 -> V_15 > 0 )
continue;
F_8 ( V_7 ) ;
V_7 -> V_8 = V_8 ;
V_8 = V_7 ;
}
}
F_9 ( & V_16 . V_17 ) ;
V_8 = V_16 . V_18 ;
if ( V_8 ) {
V_16 . V_18 = NULL ;
F_10 ( & V_16 . V_17 ) ;
goto V_13;
}
V_10 -> V_8 = NULL ;
V_12 = V_9 . V_8 ;
if ( ! V_12 )
V_16 . V_19 = V_20 ;
else {
if ( V_4 <= V_3 / 10 ) {
V_16 . V_21 += V_16 . V_19 ;
if ( V_16 . V_21 > V_20 )
V_16 . V_21 = V_20 ;
V_16 . V_19 += V_22 ;
} else {
V_16 . V_19 = V_22 ;
V_16 . V_21 = V_23 ;
}
V_5 = V_16 . V_21 ;
if ( V_5 > 4 * V_24 )
V_5 = F_11 ( V_5 ) ;
F_12 ( & V_25 , V_5 ) ;
}
F_10 ( & V_16 . V_17 ) ;
F_13 ( & V_11 ) ;
}
int F_14 ( struct V_26 * V_27 , struct V_28 * V_29 )
{
F_15 ( V_29 ) ;
return 0 ;
}
void * F_16 ( struct V_30 * V_31 , struct V_32 * V_33 ,
int V_34 , int V_35 , unsigned short V_36 )
{
struct V_6 * V_7 ;
if ( V_31 -> V_37 && F_17 ( V_31 ) > V_31 -> V_38 ) {
if ( V_31 -> V_37 ( V_31 ) )
return NULL ;
}
V_7 = F_18 ( V_31 -> V_39 , V_40 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_41 = NULL ;
V_7 -> V_33 = V_33 ;
if ( V_33 )
F_19 ( V_33 ) ;
V_7 -> V_31 = V_31 ;
F_20 ( V_7 , V_42 , true ) ;
V_7 -> V_5 = 0UL ;
V_7 -> V_43 = V_7 ;
V_7 -> V_44 = NULL ;
#ifdef F_21
V_7 -> V_45 = NULL ;
#endif
V_7 -> V_46 = V_47 ;
V_7 -> V_48 = F_14 ;
V_7 -> error = 0 ;
V_7 -> V_15 = V_35 ;
V_7 -> V_49 = 0 ;
V_7 -> V_50 = 0 ;
#ifdef F_22
V_7 -> V_51 = 0 ;
#endif
F_23 ( & V_7 -> V_14 , V_34 ) ;
V_7 -> V_52 = 0 ;
V_7 -> V_53 = V_54 ;
V_7 -> V_36 = V_36 ;
V_7 -> V_55 = 0 ;
V_7 -> V_8 = NULL ;
if ( ! ( V_36 & V_56 ) )
F_24 ( V_31 , 1 ) ;
return V_7 ;
}
static void F_8 ( struct V_6 * V_7 )
{
if ( V_7 -> V_33 == NULL || ! ( V_7 -> V_33 -> V_36 & V_57 ) ) {
V_7 -> V_46 = V_47 ;
V_7 -> V_48 = F_14 ;
}
V_7 -> V_15 = V_58 ;
}
void F_25 ( struct V_6 * V_7 )
{
F_9 ( & V_16 . V_17 ) ;
F_8 ( V_7 ) ;
V_7 -> V_8 = V_16 . V_18 ;
V_16 . V_18 = V_7 ;
if ( V_16 . V_19 > V_22 ) {
V_16 . V_19 = V_22 ;
V_16 . V_21 = V_23 ;
F_26 ( V_59 , & V_25 ,
V_16 . V_21 ) ;
}
F_10 ( & V_16 . V_17 ) ;
}
struct V_6 * F_7 ( struct V_6 * V_7 )
{
struct V_6 * V_41 ;
F_27 () ;
V_60:
V_41 = V_7 -> V_41 ;
if ( ! ( V_7 -> V_36 & V_56 ) )
F_24 ( V_7 -> V_31 , - 1 ) ;
if ( V_7 -> V_31 -> V_61 )
V_7 -> V_31 -> V_61 ( V_7 ) ;
if ( V_7 -> V_33 )
F_28 ( V_7 -> V_33 ) ;
F_29 ( V_7 -> V_31 -> V_39 , V_7 ) ;
V_7 = V_41 ;
if ( V_7 ) {
int V_62 = V_7 -> V_36 & V_63 ;
if ( F_30 ( & V_7 -> V_14 ) ) {
if ( V_62 )
goto V_60;
} else {
if ( V_62 )
return V_7 ;
}
}
return NULL ;
}
static void F_31 ( struct V_64 * V_9 )
{
struct V_6 * V_7 = F_32 ( V_9 , struct V_6 , V_64 ) ;
V_7 = F_7 ( V_7 ) ;
if ( V_7 )
F_25 ( V_7 ) ;
}
void F_33 ( struct V_6 * V_7 )
{
if ( V_7 ) {
int V_65 ;
V_65 = F_34 ( & V_7 -> V_14 ) ;
if ( F_35 ( V_65 < 0 ) )
F_36 ( L_1 ,
V_66 , V_7 , V_65 ) ;
if ( F_35 ( V_7 -> V_36 & V_67 ) && ! V_65 )
F_37 ( & V_7 -> V_64 , F_31 ) ;
}
}
T_1 * F_38 ( struct V_6 * V_7 , unsigned long V_68 )
{
T_1 * V_69 = F_39 ( sizeof( T_1 ) * V_70 , V_40 ) ;
if ( V_69 ) {
T_1 * V_71 = F_40 ( V_68 ) ;
unsigned long V_72 , V_73 ;
memcpy ( V_69 , V_71 , sizeof( T_1 ) * V_70 ) ;
V_73 = ( unsigned long ) V_69 ;
V_72 = F_41 ( & V_7 -> V_74 , V_68 , V_73 ) ;
if ( V_72 != V_68 ) {
F_42 ( V_69 ) ;
V_69 = F_40 ( V_72 ) ;
if ( V_72 & V_75 )
V_69 = NULL ;
}
}
return V_69 ;
}
void F_43 ( struct V_6 * V_7 , unsigned long V_68 )
{
unsigned long V_72 , V_73 ;
V_73 = ( ( unsigned long ) V_42 ) | V_75 ;
V_72 = F_41 ( & V_7 -> V_74 , V_68 , V_73 ) ;
if ( V_72 == V_68 )
F_42 ( F_40 ( V_68 ) ) ;
}
static void F_44 ( struct V_6 * V_7 , struct V_32 * V_33 ,
int V_76 )
{
if ( V_7 -> V_31 -> V_77 )
V_7 -> V_31 -> V_77 ( V_7 , V_33 , V_76 ) ;
if ( V_33 != V_7 -> V_33 )
return;
if ( ! V_76 ) {
V_7 -> V_46 = V_47 ;
V_7 -> V_48 = F_14 ;
} else {
V_7 -> V_33 = F_45 ( V_7 -> V_33 ) -> V_78 ;
F_19 ( V_7 -> V_33 ) ;
F_28 ( V_33 ) ;
}
}
static int F_46 ( struct V_79 * V_80 , unsigned long V_81 ,
void * V_82 )
{
struct V_32 * V_33 = F_47 ( V_82 ) ;
struct V_6 * V_7 , * V_10 = NULL ;
switch ( V_81 ) {
case V_83 :
case V_84 :
F_2 ( & V_11 ) ;
for ( V_7 = V_12 ; V_7 ; V_7 = V_7 -> V_8 ) {
V_10 = V_7 ;
F_44 ( V_7 , V_33 , V_81 != V_84 ) ;
}
F_9 ( & V_16 . V_17 ) ;
V_7 = V_16 . V_18 ;
V_16 . V_18 = NULL ;
F_10 ( & V_16 . V_17 ) ;
if ( V_10 )
V_10 -> V_8 = V_7 ;
else
V_12 = V_7 ;
for (; V_7 ; V_7 = V_7 -> V_8 )
F_44 ( V_7 , V_33 , V_81 != V_84 ) ;
F_13 ( & V_11 ) ;
break;
}
return V_85 ;
}
void T_2 F_48 ( void )
{
F_49 ( & V_86 ) ;
}
