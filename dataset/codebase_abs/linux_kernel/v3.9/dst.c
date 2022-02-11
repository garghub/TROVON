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
int F_14 ( struct V_26 * V_27 )
{
F_15 ( V_27 ) ;
return 0 ;
}
void * F_16 ( struct V_28 * V_29 , struct V_30 * V_31 ,
int V_32 , int V_33 , unsigned short V_34 )
{
struct V_6 * V_7 ;
if ( V_29 -> V_35 && F_17 ( V_29 ) > V_29 -> V_36 ) {
if ( V_29 -> V_35 ( V_29 ) )
return NULL ;
}
V_7 = F_18 ( V_29 -> V_37 , V_38 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_39 = NULL ;
V_7 -> V_31 = V_31 ;
if ( V_31 )
F_19 ( V_31 ) ;
V_7 -> V_29 = V_29 ;
F_20 ( V_7 , V_40 , true ) ;
V_7 -> V_5 = 0UL ;
V_7 -> V_41 = V_7 ;
V_7 -> V_42 = NULL ;
#ifdef F_21
V_7 -> V_43 = NULL ;
#endif
V_7 -> V_44 = F_14 ;
V_7 -> V_45 = F_14 ;
V_7 -> error = 0 ;
V_7 -> V_15 = V_33 ;
V_7 -> V_46 = 0 ;
V_7 -> V_47 = 0 ;
#ifdef F_22
V_7 -> V_48 = 0 ;
#endif
F_23 ( & V_7 -> V_14 , V_32 ) ;
V_7 -> V_49 = 0 ;
V_7 -> V_50 = V_51 ;
V_7 -> V_34 = V_34 ;
V_7 -> V_52 = 0 ;
V_7 -> V_8 = NULL ;
if ( ! ( V_34 & V_53 ) )
F_24 ( V_29 , 1 ) ;
return V_7 ;
}
static void F_8 ( struct V_6 * V_7 )
{
if ( V_7 -> V_31 == NULL || ! ( V_7 -> V_31 -> V_34 & V_54 ) )
V_7 -> V_44 = V_7 -> V_45 = F_14 ;
V_7 -> V_15 = V_55 ;
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
F_26 ( V_56 , & V_25 ,
V_16 . V_21 ) ;
}
F_10 ( & V_16 . V_17 ) ;
}
struct V_6 * F_7 ( struct V_6 * V_7 )
{
struct V_6 * V_39 ;
F_27 () ;
V_57:
V_39 = V_7 -> V_39 ;
if ( ! ( V_7 -> V_34 & V_53 ) )
F_24 ( V_7 -> V_29 , - 1 ) ;
if ( V_7 -> V_29 -> V_58 )
V_7 -> V_29 -> V_58 ( V_7 ) ;
if ( V_7 -> V_31 )
F_28 ( V_7 -> V_31 ) ;
F_29 ( V_7 -> V_29 -> V_37 , V_7 ) ;
V_7 = V_39 ;
if ( V_7 ) {
int V_59 = V_7 -> V_34 & V_60 ;
if ( F_30 ( & V_7 -> V_14 ) ) {
if ( V_59 )
goto V_57;
} else {
if ( V_59 )
return V_7 ;
}
}
return NULL ;
}
void F_31 ( struct V_6 * V_7 )
{
if ( V_7 ) {
int V_61 ;
V_61 = F_32 ( & V_7 -> V_14 ) ;
F_33 ( V_61 < 0 ) ;
if ( F_34 ( V_7 -> V_34 & V_62 ) && ! V_61 ) {
V_7 = F_7 ( V_7 ) ;
if ( V_7 )
F_25 ( V_7 ) ;
}
}
}
T_1 * F_35 ( struct V_6 * V_7 , unsigned long V_63 )
{
T_1 * V_64 = F_36 ( sizeof( T_1 ) * V_65 , V_38 ) ;
if ( V_64 ) {
T_1 * V_66 = F_37 ( V_63 ) ;
unsigned long V_67 , V_68 ;
memcpy ( V_64 , V_66 , sizeof( T_1 ) * V_65 ) ;
V_68 = ( unsigned long ) V_64 ;
V_67 = F_38 ( & V_7 -> V_69 , V_63 , V_68 ) ;
if ( V_67 != V_63 ) {
F_39 ( V_64 ) ;
V_64 = F_37 ( V_67 ) ;
if ( V_67 & V_70 )
V_64 = NULL ;
}
}
return V_64 ;
}
void F_40 ( struct V_6 * V_7 , unsigned long V_63 )
{
unsigned long V_67 , V_68 ;
V_68 = ( ( unsigned long ) V_40 ) | V_70 ;
V_67 = F_38 ( & V_7 -> V_69 , V_63 , V_68 ) ;
if ( V_67 == V_63 )
F_39 ( F_37 ( V_63 ) ) ;
}
void F_41 ( struct V_26 * V_27 , struct V_6 * V_7 )
{
F_33 ( ! F_42 () && ! F_43 () ) ;
if ( F_34 ( V_7 -> V_34 & V_62 ) ) {
F_44 ( V_7 ) ;
F_45 ( V_27 , V_7 ) ;
} else {
V_27 -> V_71 = ( unsigned long ) V_7 | V_72 ;
}
}
static void F_46 ( struct V_6 * V_7 , struct V_30 * V_31 ,
int V_73 )
{
if ( V_7 -> V_29 -> V_74 )
V_7 -> V_29 -> V_74 ( V_7 , V_31 , V_73 ) ;
if ( V_31 != V_7 -> V_31 )
return;
if ( ! V_73 ) {
V_7 -> V_44 = V_7 -> V_45 = F_14 ;
} else {
V_7 -> V_31 = F_47 ( V_7 -> V_31 ) -> V_75 ;
F_19 ( V_7 -> V_31 ) ;
F_28 ( V_31 ) ;
}
}
static int F_48 ( struct V_76 * V_77 , unsigned long V_78 ,
void * V_79 )
{
struct V_30 * V_31 = V_79 ;
struct V_6 * V_7 , * V_10 = NULL ;
switch ( V_78 ) {
case V_80 :
case V_81 :
F_2 ( & V_11 ) ;
for ( V_7 = V_12 ; V_7 ; V_7 = V_7 -> V_8 ) {
V_10 = V_7 ;
F_46 ( V_7 , V_31 , V_78 != V_81 ) ;
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
F_46 ( V_7 , V_31 , V_78 != V_81 ) ;
F_13 ( & V_11 ) ;
break;
}
return V_82 ;
}
void T_2 F_49 ( void )
{
F_50 ( & V_83 ) ;
}
