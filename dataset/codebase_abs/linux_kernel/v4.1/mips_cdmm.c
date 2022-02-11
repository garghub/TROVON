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
static int F_24 ( struct V_28 * V_21 )
{
unsigned long V_37 , V_30 ;
int V_5 = 0 ;
if ( F_25 ( V_21 ) )
return F_26 ( V_21 ) ;
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
if ( ! V_21 -> V_42 && V_44 )
V_21 -> V_42 = V_44 () ;
if ( ! V_21 -> V_42 )
V_21 -> V_42 = V_45 ;
if ( ! V_21 -> V_42 ) {
V_21 -> V_42 = 1 ;
F_27 ( L_5 ,
F_16 () ) ;
}
if ( V_21 -> V_42 == 1 ) {
V_5 = - V_36 ;
goto V_43;
}
V_45 = V_21 -> V_42 ;
F_28 ( L_6 ,
F_16 () , & V_21 -> V_42 ) ;
V_37 = F_23 () ;
V_37 &= ( 1ul << V_39 ) - 1 ;
V_37 |= ( V_21 -> V_42 >> V_40 )
<< V_39 ;
V_37 |= V_38 ;
F_29 ( V_37 ) ;
F_30 () ;
V_21 -> V_46 = ( void V_47 * ) F_31 ( V_21 -> V_42 ) ;
V_21 -> V_48 = 1 + ( ( V_37 & V_49 ) >>
V_50 ) ;
V_21 -> V_51 = ! ! ( V_37 & V_52 ) ;
V_43:
F_21 ( V_30 ) ;
return V_5 ;
}
void V_47 * F_32 ( unsigned int V_53 )
{
struct V_28 * V_21 ;
void V_47 * V_54 ;
T_2 V_55 ;
unsigned int V_56 , type , V_57 ;
int V_58 ;
if ( F_33 ( ! V_53 ) )
return F_34 ( - V_32 ) ;
V_21 = F_14 () ;
V_58 = F_24 ( V_21 ) ;
if ( V_58 )
return F_34 ( V_58 ) ;
V_56 = V_21 -> V_51 ;
V_54 = V_21 -> V_46 ;
for (; V_56 < V_21 -> V_48 ; V_56 += V_57 + 1 ) {
V_55 = F_35 ( V_54 + V_56 * V_59 ) ;
type = ( V_55 & V_60 ) >> V_61 ;
if ( type == V_53 )
return V_54 + V_56 * V_59 ;
V_57 = ( V_55 & V_62 ) >> V_63 ;
}
return F_34 ( - V_32 ) ;
}
static void F_36 ( struct V_6 * V_4 )
{
struct V_3 * V_9 = F_3 ( V_4 ) ;
F_37 ( V_9 ) ;
}
static void F_38 ( struct V_28 * V_21 )
{
void V_47 * V_54 ;
T_2 V_55 ;
unsigned int V_56 , type , V_57 , V_17 ;
struct V_3 * V_4 ;
unsigned int V_16 = F_16 () ;
int V_5 = 0 ;
int V_64 = 0 ;
V_56 = V_21 -> V_51 ;
V_54 = V_21 -> V_46 ;
V_21 -> V_65 = true ;
F_39 ( L_7 , V_16 , V_21 -> V_48 ) ;
for (; V_56 < V_21 -> V_48 ; V_56 += V_57 + 1 ) {
V_55 = F_35 ( V_54 + V_56 * V_59 ) ;
type = ( V_55 & V_60 ) >> V_61 ;
V_57 = ( V_55 & V_62 ) >> V_63 ;
V_17 = ( V_55 & V_66 ) >> V_67 ;
if ( ! type )
continue;
F_39 ( L_8 ,
V_16 , V_64 , V_56 , V_56 * V_59 ,
( V_56 + V_57 + 1 ) * V_59 - 1 ,
type , V_17 ) ;
V_4 = F_20 ( sizeof( * V_4 ) , V_68 ) ;
if ( ! V_4 )
break;
V_4 -> V_16 = V_16 ;
V_4 -> V_69 . V_70 = V_21 -> V_42 + V_56 * V_59 ;
V_4 -> V_69 . V_71 = V_21 -> V_42 +
( V_56 + V_57 + 1 ) * V_59 - 1 ;
V_4 -> V_69 . V_30 = V_72 ;
V_4 -> type = type ;
V_4 -> V_17 = V_17 ;
V_4 -> V_4 . V_73 = F_40 ( V_16 ) ;
V_4 -> V_4 . V_21 = & V_22 ;
V_4 -> V_4 . V_64 = F_41 ( & V_74 ) ;
V_4 -> V_4 . V_75 = F_36 ;
F_42 ( & V_4 -> V_4 , L_9 , V_16 , V_64 ) ;
++ V_64 ;
V_5 = F_43 ( & V_4 -> V_4 ) ;
if ( V_5 ) {
F_44 ( & V_4 -> V_4 ) ;
F_37 ( V_4 ) ;
}
}
}
static long F_45 ( void * V_18 )
{
struct V_28 * V_21 ;
long V_5 ;
V_5 = F_46 ( & V_22 , NULL , V_18 ,
V_76 ) ;
V_21 = F_14 () ;
if ( ! F_25 ( V_21 ) )
V_21 -> V_41 = true ;
return V_5 ;
}
static long F_47 ( void * V_18 )
{
struct V_28 * V_21 ;
long V_5 ;
V_21 = F_14 () ;
V_5 = F_24 ( V_21 ) ;
if ( V_5 )
return V_5 ;
V_21 -> V_41 = false ;
if ( ! V_21 -> V_65 )
F_38 ( V_21 ) ;
else
V_5 = F_46 ( & V_22 , NULL , V_18 ,
V_77 ) ;
return V_5 ;
}
static int F_48 ( struct V_78 * V_79 ,
unsigned long V_80 , void * V_18 )
{
unsigned int V_16 = ( unsigned int ) V_18 ;
switch ( V_80 & ~ V_81 ) {
case V_82 :
case V_83 :
F_49 ( V_16 , F_47 , & V_16 ) ;
break;
case V_84 :
F_49 ( V_16 , F_45 , & V_16 ) ;
break;
default:
return V_85 ;
}
return V_86 ;
}
static int T_3 F_50 ( void )
{
unsigned int V_16 ;
int V_5 ;
V_5 = F_51 ( & V_22 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_52 ( & V_87 ) ;
if ( V_5 ) {
F_53 ( L_10 ) ;
goto V_43;
}
F_54 (cpu)
F_49 ( V_16 , F_47 , & V_16 ) ;
return 0 ;
V_43:
F_55 ( & V_22 ) ;
return V_5 ;
}
