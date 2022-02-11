static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 ;
}
static const char * F_3 ( struct V_1 * V_2 ,
unsigned V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_7 [ V_6 ] . V_8 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned V_9 ,
const unsigned * * V_10 , unsigned * V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_10 = & V_4 -> V_7 [ V_9 ] . V_12 ;
* V_11 = 1 ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 , struct V_13 * V_14 ,
unsigned V_15 )
{
F_6 ( V_14 , L_1 , V_16 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_17 ;
}
static const char * F_8 ( struct V_1 * V_2 ,
unsigned V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_18 [ V_6 ] -> V_8 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned V_19 ,
const char * const * * V_20 ,
unsigned * const V_21 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_20 = & V_4 -> V_18 [ V_19 ] -> V_8 ;
* V_21 = 1 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned V_19 ,
unsigned V_9 )
{
return 0 ;
}
static void F_11 ( struct V_1 * V_2 , unsigned V_19 ,
unsigned V_9 )
{
}
static inline int F_12 ( struct V_22 * V_23 , unsigned V_15 )
{
if ( F_13 ( V_23 , V_15 ,
V_24 ,
V_25 ) != 0 )
return - V_26 ;
if ( F_13 ( V_23 , V_15 ,
V_24 ,
V_27 ) != 0 )
return - V_26 ;
return 0 ;
}
static int F_14 ( struct V_22 * V_23 , unsigned V_15 ,
int V_28 )
{
unsigned long V_29 ;
int V_30 ;
int V_31 = - V_26 ;
F_15 ( & V_23 -> V_32 , V_29 ) ;
V_30 = V_23 -> V_33 [ V_15 ] . V_29 & V_34 ;
switch ( V_30 ) {
case V_35 :
break;
case V_36 :
case V_37 :
case V_38 :
case V_39 :
F_13 ( V_23 , V_15 , V_30 , V_40 ) ;
break;
default:
goto V_41;
}
if ( F_13 ( V_23 , V_15 , V_28 ,
V_25 ) != 0 )
goto V_41;
if ( F_13 ( V_23 , V_15 , V_28 ,
V_27 ) != 0 )
goto V_41;
V_23 -> V_33 [ V_15 ] . V_29 &= ~ V_34 ;
V_23 -> V_33 [ V_15 ] . V_29 |= V_28 ;
V_31 = 0 ;
V_41:
F_16 ( & V_23 -> V_32 , V_29 ) ;
return V_31 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_42 * V_43 ,
unsigned V_15 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_22 * V_23 = V_4 -> V_23 ;
unsigned long V_29 ;
int V_31 , V_30 ;
F_15 ( & V_23 -> V_32 , V_29 ) ;
V_30 = V_23 -> V_33 [ V_15 ] . V_29 & V_34 ;
switch ( V_30 ) {
case V_24 :
F_18 ( L_2
L_3 ) ;
V_31 = F_12 ( V_23 , V_15 ) ;
if ( F_19 ( V_31 < 0 ) )
goto V_41;
break;
case V_35 :
case V_37 :
case V_36 :
break;
default:
F_20 ( L_4 , V_30 ) ;
V_31 = - V_44 ;
goto V_41;
}
V_31 = 0 ;
V_41:
F_16 ( & V_23 -> V_32 , V_29 ) ;
return V_31 ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_42 * V_43 ,
unsigned V_15 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_22 * V_23 = V_4 -> V_23 ;
unsigned long V_29 ;
int V_30 ;
F_15 ( & V_23 -> V_32 , V_29 ) ;
V_30 = V_23 -> V_33 [ V_15 ] . V_29 & V_34 ;
F_13 ( V_23 , V_15 , V_30 , V_40 ) ;
F_16 ( & V_23 -> V_32 , V_29 ) ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_42 * V_43 ,
unsigned V_15 , bool V_45 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int type = V_45 ? V_37 : V_36 ;
return F_14 ( V_4 -> V_23 , V_15 , type ) ;
}
static int F_23 ( struct V_1 * V_2 , unsigned V_46 ,
unsigned long * V_47 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_22 * V_23 = V_4 -> V_23 ;
* V_47 = V_23 -> V_33 [ V_46 ] . V_29 & V_34 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , unsigned V_46 ,
unsigned long V_47 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_47 >= V_34 )
return - V_26 ;
return F_14 ( V_4 -> V_23 , V_46 , V_47 ) ;
}
static void F_25 ( struct V_1 * V_2 ,
struct V_13 * V_14 , unsigned V_46 )
{
const char * V_48 [] = {
[ V_49 ] = L_5 ,
[ V_24 ] = L_6 ,
[ V_35 ] = L_7 ,
[ V_36 ] = L_8 ,
[ V_37 ] = L_9 ,
[ V_38 ] = L_10 ,
[ V_39 ] = L_11 ,
} ;
unsigned long V_47 ;
int V_50 ;
V_50 = F_23 ( V_2 , V_46 , & V_47 ) ;
if ( F_19 ( V_50 != 0 ) )
return;
F_6 ( V_14 , L_12 , V_48 [ V_47 ] ) ;
}
static inline void T_1 F_26 ( struct V_22 * V_23 ,
struct V_3 * V_4 ,
struct V_51 * V_52 ,
unsigned V_15 )
{
struct V_53 * V_54 ;
unsigned long V_29 ;
int V_55 ;
V_52 -> V_29 &= ~ V_34 ;
if ( F_27 ( V_23 , V_15 , & V_54 , & V_55 ) == 0 )
V_52 -> V_29 |= V_35 ;
else {
V_52 -> V_29 |= V_24 ;
F_15 ( & V_4 -> V_32 , V_29 ) ;
V_4 -> V_17 ++ ;
F_16 ( & V_4 -> V_32 , V_29 ) ;
}
}
static int T_1 F_28 ( struct V_22 * V_23 ,
struct V_3 * V_4 )
{
unsigned long V_29 ;
int V_56 ;
V_4 -> V_5 = V_23 -> V_57 - V_23 -> V_58 + 1 ;
V_4 -> V_7 = F_29 ( sizeof( struct V_59 ) * V_4 -> V_5 ,
V_60 ) ;
if ( F_19 ( ! V_4 -> V_7 ) ) {
V_4 -> V_5 = 0 ;
return - V_61 ;
}
F_15 ( & V_23 -> V_32 , V_29 ) ;
for ( V_56 = 0 ; V_56 < V_4 -> V_5 ; V_56 ++ ) {
struct V_59 * V_46 = V_4 -> V_7 + V_56 ;
struct V_51 * V_52 = V_23 -> V_33 + V_56 ;
V_46 -> V_12 = V_23 -> V_58 + V_56 ;
V_46 -> V_8 = V_52 -> V_8 ;
if ( F_19 ( ! V_52 -> V_62 ) )
continue;
F_26 ( V_23 , V_4 , V_52 , V_56 ) ;
}
F_16 ( & V_23 -> V_32 , V_29 ) ;
V_63 . V_10 = V_4 -> V_7 ;
V_63 . V_64 = V_4 -> V_5 ;
return 0 ;
}
static int T_1 F_30 ( struct V_22 * V_23 ,
struct V_3 * V_4 )
{
unsigned long V_29 ;
int V_56 , V_65 ;
V_4 -> V_18 = F_31 ( V_4 -> V_17 * sizeof( void * ) ,
V_60 ) ;
if ( F_19 ( ! V_4 -> V_18 ) )
return - V_61 ;
F_15 ( & V_4 -> V_32 , V_29 ) ;
for ( V_56 = V_65 = 0 ; V_56 < V_4 -> V_5 ; V_56 ++ ) {
struct V_51 * V_52 = V_23 -> V_33 + V_56 ;
if ( ( V_52 -> V_29 & V_34 ) == V_24 )
V_4 -> V_18 [ V_65 ++ ] = V_52 ;
}
F_16 ( & V_4 -> V_32 , V_29 ) ;
return 0 ;
}
static int T_1 F_32 ( struct V_66 * V_67 )
{
struct V_22 * V_23 ;
int V_31 ;
if ( F_19 ( ! V_68 ) )
return - V_69 ;
V_23 = V_68 -> V_23 ;
V_31 = F_28 ( V_23 , V_68 ) ;
if ( F_19 ( V_31 != 0 ) )
return V_31 ;
V_31 = F_30 ( V_23 , V_68 ) ;
if ( F_19 ( V_31 != 0 ) )
goto V_70;
V_68 -> V_71 = F_33 ( & V_63 , & V_67 -> V_72 ,
V_68 ) ;
if ( F_34 ( V_68 -> V_71 ) ) {
V_31 = F_35 ( V_68 -> V_71 ) ;
goto V_73;
}
V_74 . V_64 = V_23 -> V_57 - V_23 -> V_58 + 1 ;
V_74 . V_75 = V_23 -> V_58 ;
V_74 . V_76 = V_23 -> V_58 ;
F_36 ( V_68 -> V_71 , & V_74 ) ;
F_37 ( V_67 , V_68 ) ;
return 0 ;
V_73:
F_38 ( V_68 -> V_18 ) ;
V_70:
F_38 ( V_68 -> V_7 ) ;
F_38 ( V_68 ) ;
return V_31 ;
}
static int T_2 F_39 ( struct V_66 * V_67 )
{
struct V_3 * V_4 = F_40 ( V_67 ) ;
F_41 ( V_4 -> V_71 ) ;
F_37 ( V_67 , NULL ) ;
F_38 ( V_68 -> V_18 ) ;
F_38 ( V_68 -> V_7 ) ;
F_38 ( V_68 ) ;
return 0 ;
}
static int F_42 ( void )
{
int V_50 ;
V_50 = F_43 ( & V_77 ) ;
if ( F_44 ( ! V_50 ) ) {
V_50 = F_45 ( & V_78 ) ;
if ( F_19 ( V_50 ) )
F_46 ( & V_77 ) ;
}
return V_50 ;
}
int F_47 ( struct V_22 * V_23 )
{
V_68 = F_31 ( sizeof( struct V_3 ) , V_60 ) ;
if ( F_19 ( ! V_68 ) )
return - V_61 ;
F_48 ( & V_68 -> V_32 ) ;
V_68 -> V_23 = V_23 ;
return F_42 () ;
}
static void T_3 F_49 ( void )
{
F_46 ( & V_77 ) ;
}
