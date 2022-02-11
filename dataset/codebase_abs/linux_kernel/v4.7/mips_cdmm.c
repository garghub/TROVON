static const struct V_1 *
F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = 0 ;
for (; V_2 -> type ; ++ V_2 ) {
V_5 = ( V_4 -> type == V_2 -> type ) ;
if ( V_5 )
break;
}
return V_5 ? V_2 : NULL ;
}
static int F_2 ( struct V_6 * V_4 , struct V_7 * V_8 )
{
struct V_3 * V_9 = F_3 ( V_4 ) ;
struct V_10 * V_11 = F_4 ( V_8 ) ;
return F_1 ( V_11 -> V_12 , V_9 ) != NULL ;
}
static int F_5 ( struct V_6 * V_4 , struct V_13 * V_14 )
{
struct V_3 * V_9 = F_3 ( V_4 ) ;
int V_15 = 0 ;
V_15 = F_6 ( V_14 , L_1 , V_9 -> V_16 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_6 ( V_14 , L_2 , V_9 -> type ) ;
if ( V_15 )
return V_15 ;
V_15 = F_6 ( V_14 , L_3 , V_9 -> V_17 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_6 ( V_14 , L_4 , V_9 -> type ) ;
return V_15 ;
}
static long F_7 ( void * V_18 )
{
struct V_19 * V_20 = V_18 ;
void (* F_8)( struct V_3 * ) = V_20 -> F_8 ;
F_8 ( V_20 -> V_4 ) ;
return 0 ;
}
static long F_9 ( void * V_18 )
{
struct V_19 * V_20 = V_18 ;
int (* F_8)( struct V_3 * ) = V_20 -> F_8 ;
return F_8 ( V_20 -> V_4 ) ;
}
int F_10 ( struct V_10 * V_8 )
{
V_8 -> V_8 . V_21 = & V_22 ;
if ( V_8 -> V_23 )
V_8 -> V_8 . V_23 = V_24 ;
if ( V_8 -> remove )
V_8 -> V_8 . remove = V_25 ;
if ( V_8 -> V_26 )
V_8 -> V_8 . V_26 = V_27 ;
return F_11 ( & V_8 -> V_8 ) ;
}
void F_12 ( struct V_10 * V_8 )
{
F_13 ( & V_8 -> V_8 ) ;
}
static struct V_28 * F_14 ( void )
{
struct V_28 * V_21 , * * V_29 ;
unsigned long V_30 ;
unsigned int V_16 ;
if ( ! V_31 )
return F_15 ( - V_32 ) ;
V_16 = F_16 () ;
if ( V_16 == 0 )
return & V_33 ;
V_29 = F_17 ( & V_34 , V_16 ) ;
F_18 ( V_30 ) ;
V_21 = * V_29 ;
if ( F_19 ( ! V_21 ) ) {
V_21 = F_20 ( sizeof( * V_21 ) , V_35 ) ;
if ( F_19 ( ! V_21 ) )
V_21 = F_15 ( - V_36 ) ;
else
* V_29 = V_21 ;
}
F_21 ( V_30 ) ;
return V_21 ;
}
static T_1 F_22 ( void )
{
unsigned long V_37 = F_23 () ;
if ( ! ( V_37 & V_38 ) )
return 0 ;
return ( V_37 >> V_39 )
<< V_40 ;
}
T_1 __weak F_24 ( void )
{
return 0 ;
}
static int F_25 ( struct V_28 * V_21 )
{
unsigned long V_37 , V_30 ;
int V_5 = 0 ;
if ( F_26 ( V_21 ) )
return F_27 ( V_21 ) ;
F_18 ( V_30 ) ;
if ( V_21 -> V_41 ) {
if ( V_21 -> V_42 == F_22 () )
goto V_43;
V_21 -> V_41 = false ;
} else if ( V_21 -> V_42 > 1 ) {
goto V_43;
}
if ( ! V_21 -> V_42 )
V_21 -> V_42 = F_22 () ;
if ( ! V_21 -> V_42 )
V_21 -> V_42 = F_24 () ;
if ( ! V_21 -> V_42 )
V_21 -> V_42 = V_44 ;
if ( ! V_21 -> V_42 ) {
V_21 -> V_42 = 1 ;
F_28 ( L_5 ,
F_16 () ) ;
}
if ( V_21 -> V_42 == 1 ) {
V_5 = - V_36 ;
goto V_43;
}
V_44 = V_21 -> V_42 ;
F_29 ( L_6 ,
F_16 () , & V_21 -> V_42 ) ;
V_37 = F_23 () ;
V_37 &= ( 1ul << V_39 ) - 1 ;
V_37 |= ( V_21 -> V_42 >> V_40 )
<< V_39 ;
V_37 |= V_38 ;
F_30 ( V_37 ) ;
F_31 () ;
V_21 -> V_45 = ( void V_46 * ) F_32 ( V_21 -> V_42 ) ;
V_21 -> V_47 = 1 + ( ( V_37 & V_48 ) >>
V_49 ) ;
V_21 -> V_50 = ! ! ( V_37 & V_51 ) ;
V_43:
F_21 ( V_30 ) ;
return V_5 ;
}
void V_46 * F_33 ( unsigned int V_52 )
{
struct V_28 * V_21 ;
void V_46 * V_53 ;
T_2 V_54 ;
unsigned int V_55 , type , V_56 ;
int V_57 ;
if ( F_34 ( ! V_52 ) )
return F_35 ( - V_32 ) ;
V_21 = F_14 () ;
V_57 = F_25 ( V_21 ) ;
if ( V_57 )
return F_35 ( V_57 ) ;
V_55 = V_21 -> V_50 ;
V_53 = V_21 -> V_45 ;
for (; V_55 < V_21 -> V_47 ; V_55 += V_56 + 1 ) {
V_54 = F_36 ( V_53 + V_55 * V_58 ) ;
type = ( V_54 & V_59 ) >> V_60 ;
if ( type == V_52 )
return V_53 + V_55 * V_58 ;
V_56 = ( V_54 & V_61 ) >> V_62 ;
}
return F_35 ( - V_32 ) ;
}
static void F_37 ( struct V_6 * V_4 )
{
struct V_3 * V_9 = F_3 ( V_4 ) ;
F_38 ( V_9 ) ;
}
static void F_39 ( struct V_28 * V_21 )
{
void V_46 * V_53 ;
T_2 V_54 ;
unsigned int V_55 , type , V_56 , V_17 ;
struct V_3 * V_4 ;
unsigned int V_16 = F_16 () ;
int V_5 = 0 ;
int V_63 = 0 ;
V_55 = V_21 -> V_50 ;
V_53 = V_21 -> V_45 ;
V_21 -> V_64 = true ;
F_40 ( L_7 , V_16 , V_21 -> V_47 ) ;
for (; V_55 < V_21 -> V_47 ; V_55 += V_56 + 1 ) {
V_54 = F_36 ( V_53 + V_55 * V_58 ) ;
type = ( V_54 & V_59 ) >> V_60 ;
V_56 = ( V_54 & V_61 ) >> V_62 ;
V_17 = ( V_54 & V_65 ) >> V_66 ;
if ( ! type )
continue;
F_40 ( L_8 ,
V_16 , V_63 , V_55 , V_55 * V_58 ,
( V_55 + V_56 + 1 ) * V_58 - 1 ,
type , V_17 ) ;
V_4 = F_20 ( sizeof( * V_4 ) , V_67 ) ;
if ( ! V_4 )
break;
V_4 -> V_16 = V_16 ;
V_4 -> V_68 . V_69 = V_21 -> V_42 + V_55 * V_58 ;
V_4 -> V_68 . V_70 = V_21 -> V_42 +
( V_55 + V_56 + 1 ) * V_58 - 1 ;
V_4 -> V_68 . V_30 = V_71 ;
V_4 -> type = type ;
V_4 -> V_17 = V_17 ;
V_4 -> V_4 . V_72 = F_41 ( V_16 ) ;
V_4 -> V_4 . V_21 = & V_22 ;
V_4 -> V_4 . V_63 = F_42 ( & V_73 ) ;
V_4 -> V_4 . V_74 = F_37 ;
F_43 ( & V_4 -> V_4 , L_9 , V_16 , V_63 ) ;
++ V_63 ;
V_5 = F_44 ( & V_4 -> V_4 ) ;
if ( V_5 ) {
F_45 ( & V_4 -> V_4 ) ;
F_38 ( V_4 ) ;
}
}
}
static long F_46 ( void * V_18 )
{
struct V_28 * V_21 ;
long V_5 ;
V_5 = F_47 ( & V_22 , NULL , V_18 ,
V_75 ) ;
V_21 = F_14 () ;
if ( ! F_26 ( V_21 ) )
V_21 -> V_41 = true ;
return V_5 ;
}
static long F_48 ( void * V_18 )
{
struct V_28 * V_21 ;
long V_5 ;
V_21 = F_14 () ;
V_5 = F_25 ( V_21 ) ;
if ( V_5 )
return V_5 ;
V_21 -> V_41 = false ;
if ( ! V_21 -> V_64 )
F_39 ( V_21 ) ;
else
V_5 = F_47 ( & V_22 , NULL , V_18 ,
V_76 ) ;
return V_5 ;
}
static int F_49 ( struct V_77 * V_78 ,
unsigned long V_79 , void * V_18 )
{
unsigned int V_16 = ( unsigned int ) V_18 ;
switch ( V_79 & ~ V_80 ) {
case V_81 :
case V_82 :
F_48 ( & V_16 ) ;
break;
case V_83 :
F_46 ( & V_16 ) ;
break;
default:
return V_84 ;
}
return V_85 ;
}
static int T_3 F_50 ( void )
{
unsigned int V_16 ;
int V_5 ;
V_5 = F_51 ( & V_22 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_52 ( & V_86 ) ;
if ( V_5 ) {
F_53 ( L_10 ) ;
goto V_43;
}
F_54 (cpu)
F_55 ( V_16 , F_48 , & V_16 ) ;
return 0 ;
V_43:
F_56 ( & V_22 ) ;
return V_5 ;
}
