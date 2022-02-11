static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline int F_3 ( struct V_1 * V_5 ,
int V_6 )
{
int V_7 ;
F_4 ( & V_5 -> V_8 ) ;
V_7 = V_5 -> V_9 & V_6 ;
F_5 ( & V_5 -> V_8 ) ;
return V_7 ;
}
static inline void F_6 ( struct V_1 * V_5 )
{
F_7 ( V_5 -> V_10 ,
! F_3 ( V_5 , V_11 ) ) ;
}
static inline void F_8 ( struct V_1 * V_5 )
{
F_7 ( V_5 -> V_10 ,
! F_3 ( V_5 , V_12 ) ) ;
}
static inline struct V_13 *
F_9 ( struct V_1 * V_5 )
{
struct V_14 * V_15 ;
V_15 = F_2 ( V_5 ,
struct V_14 ,
V_16 ) ;
return V_15 -> V_17 ;
}
static struct V_18 *
F_10 ( struct V_1 * V_5 )
{
struct V_14 * V_15 ;
V_15 = F_2 ( V_5 ,
struct V_14 ,
V_16 ) ;
return & V_15 -> V_19 ;
}
static inline void F_11 ( struct V_1 * V_5 )
{
F_4 ( & V_5 -> V_8 ) ;
V_5 -> V_9 &= ~ V_11 ;
F_5 ( & V_5 -> V_8 ) ;
}
static inline int F_12 ( int V_20 )
{
int V_21 = V_22 ;
if ( V_20 == V_22 )
V_21 = V_23 ;
else if ( V_20 == V_24 )
V_21 = V_24 ;
return V_21 ;
}
static void F_13 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_25 ;
F_14 ( V_26 , L_1 ,
V_5 -> V_27 , V_5 -> V_28 , V_5 -> V_29 ,
V_5 -> V_30 ) ;
F_4 ( & V_5 -> V_8 ) ;
V_25 = F_15 ( & V_5 -> V_4 ) ;
if ( V_25 ) {
F_14 ( V_31 , L_2 ,
V_25 , V_5 -> V_27 , V_5 -> V_28 ) ;
F_5 ( & V_5 -> V_8 ) ;
return;
}
F_16 ( V_5 -> V_30 == V_32 ,
L_3 ,
V_5 -> V_27 , V_5 -> V_28 , V_5 -> V_9 ) ;
if ( V_5 -> V_30 < V_5 -> V_29 ) {
if ( V_5 -> V_30 <=
F_12 ( V_5 -> V_33 ) ) {
V_5 -> V_33 = V_23 ;
V_5 -> V_9 &= ~ V_12 ;
}
}
V_5 -> V_29 = V_5 -> V_30 ;
V_5 -> V_30 = V_32 ;
V_5 -> V_9 |= V_34 ;
V_5 -> V_9 &= ~ V_11 ;
F_5 ( & V_5 -> V_8 ) ;
F_17 ( & V_5 -> V_10 ) ;
}
static inline void F_18 ( struct V_1 * V_5 )
{
struct V_18 * V_18 ;
V_18 = F_10 ( V_5 ) ;
if ( ! F_19 ( V_18 ) )
F_20 () ;
}
static void F_21 ( struct V_1 * V_5 )
{
if ( ! ( V_5 -> V_9 & V_35 ) ) {
F_18 ( V_5 ) ;
F_22 ( & V_5 -> V_36 , V_37 ) ;
F_23 ( V_38 , & V_5 -> V_36 ) ;
V_5 -> V_9 |= V_35 ;
}
}
static void F_24 ( struct V_1 * V_5 )
{
int V_39 = 0 ;
if ( ! ( V_5 -> V_9 & V_12 ) )
return;
switch ( V_5 -> V_33 ) {
case V_22 :
if ( ! V_5 -> V_40 && ! V_5 -> V_41 )
V_39 = 1 ;
break;
case V_24 :
if ( ! V_5 -> V_40 )
V_39 = 1 ;
break;
default:
F_20 () ;
}
if ( V_39 )
F_21 ( V_5 ) ;
}
static void F_25 ( struct V_2 * V_3 , int V_20 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_14 ( V_26 , L_4 ,
V_5 -> V_27 , V_5 -> V_28 , V_20 , V_5 -> V_29 ) ;
F_4 ( & V_5 -> V_8 ) ;
V_5 -> V_9 |= V_12 ;
if ( V_20 > V_5 -> V_33 )
V_5 -> V_33 = V_20 ;
F_21 ( V_5 ) ;
F_5 ( & V_5 -> V_8 ) ;
F_17 ( & V_5 -> V_10 ) ;
}
static void F_26 ( struct V_2 * V_3 , int V_25 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_14 ( V_26 , L_5 ,
V_5 -> V_27 , V_5 -> V_28 , V_5 -> V_9 ) ;
if ( V_25 )
F_14 ( V_31 , L_6 , V_25 ) ;
F_4 ( & V_5 -> V_8 ) ;
if ( V_5 -> V_9 & V_42
&& ! ( V_5 -> V_9 & V_43 ) ) {
V_5 -> V_29 = V_32 ;
} else if ( V_25 == V_44 ) {
F_27 ( ! ( V_5 -> V_9 & V_43 ) ) ;
V_5 -> V_9 &= ~ V_43 ;
goto V_45;
} else {
F_27 ( ! ( V_5 -> V_9 & V_43 ) ) ;
V_5 -> V_30 = V_32 ;
V_5 -> V_9 &= ~ V_43 ;
if ( V_5 -> V_9 & V_12 )
F_21 ( V_5 ) ;
}
V_5 -> V_9 &= ~ V_11 ;
V_45:
F_5 ( & V_5 -> V_8 ) ;
F_17 ( & V_5 -> V_10 ) ;
}
static inline void F_28 ( struct V_1 * V_5 )
{
struct V_18 * V_18 ;
V_18 = F_10 ( V_5 ) ;
F_29 ( V_18 ) ;
}
static void V_37 ( struct V_46 * V_47 )
{
int V_21 , V_25 ;
struct V_1 * V_5 =
F_2 ( V_47 , struct V_1 , V_36 ) ;
struct V_13 * V_48 =
F_9 ( V_5 ) ;
F_14 ( 0 , L_7 , V_5 -> V_27 , V_5 -> V_28 ) ;
F_4 ( & V_5 -> V_8 ) ;
F_16 ( ! ( V_5 -> V_9 & V_35 ) ,
L_8 ,
V_5 -> V_27 , V_5 -> V_28 , V_5 -> V_9 ) ;
V_5 -> V_9 &= ~ V_35 ;
if ( ! ( V_5 -> V_9 & V_12 ) ) {
F_14 ( V_26 , L_9 ,
V_5 -> V_27 , V_5 -> V_28 ) ;
F_5 ( & V_5 -> V_8 ) ;
goto V_49;
}
if ( V_5 -> V_9 & V_42 ) {
F_14 ( V_26 , L_10 ,
V_5 -> V_27 , V_5 -> V_28 ) ;
F_5 ( & V_5 -> V_8 ) ;
goto V_49;
}
if ( V_5 -> V_9 & V_11 ) {
if ( V_5 -> V_9 & V_43 ) {
F_14 ( V_26 , L_11 ,
V_5 -> V_27 , V_5 -> V_28 ) ;
F_5 ( & V_5 -> V_8 ) ;
goto V_49;
}
V_5 -> V_9 |= V_43 ;
F_5 ( & V_5 -> V_8 ) ;
V_25 = F_30 ( V_48 , & V_5 -> V_4 ,
V_50 ) ;
if ( V_25 )
F_31 ( L_12 , V_25 , V_5 ) ;
goto V_49;
}
if ( ( V_5 -> V_33 == V_22 )
&& ( V_5 -> V_40 || V_5 -> V_41 ) ) {
F_5 ( & V_5 -> V_8 ) ;
F_14 ( V_26 , L_13 ,
V_5 -> V_27 , V_5 -> V_28 ,
V_5 -> V_40 , V_5 -> V_41 ) ;
goto V_49;
}
if ( ( V_5 -> V_33 == V_24 )
&& V_5 -> V_40 ) {
F_5 ( & V_5 -> V_8 ) ;
F_14 ( V_26 , L_14 ,
V_5 -> V_27 , V_5 -> V_28 ,
V_5 -> V_40 ) ;
goto V_49;
}
V_21 = F_12 ( V_5 -> V_33 ) ;
V_5 -> V_30 = V_21 ;
V_5 -> V_9 |= V_11 ;
F_14 ( V_26 , L_15 ,
V_5 -> V_27 , V_5 -> V_28 , V_5 -> V_29 , V_21 ) ;
F_5 ( & V_5 -> V_8 ) ;
V_25 = F_32 ( V_48 , V_21 , & V_5 -> V_4 ,
V_51 | V_52 ,
V_5 -> V_28 ,
V_5 -> V_27 ) ;
if ( V_25 ) {
F_31 ( L_16 , V_25 , V_5 ) ;
F_11 ( V_5 ) ;
}
V_49:
F_28 ( V_5 ) ;
}
static inline void F_33 ( struct V_1 * V_5 ,
int V_20 )
{
switch( V_20 ) {
case V_22 :
V_5 -> V_40 ++ ;
break;
case V_24 :
V_5 -> V_41 ++ ;
break;
default:
F_20 () ;
}
}
static inline int
F_34 ( struct V_1 * V_5 ,
int V_53 )
{
F_27 ( ! ( V_5 -> V_9 & V_12 ) ) ;
return V_53 <= F_12 ( V_5 -> V_33 ) ;
}
int F_35 ( struct V_1 * V_5 ,
int V_20 ,
int V_54 )
{
int V_25 , V_55 ;
struct V_13 * V_48 =
F_9 ( V_5 ) ;
if ( V_20 != V_22 &&
V_20 != V_24 ) {
F_14 ( V_31 , L_17 ,
V_5 -> V_27 , V_5 -> V_28 ) ;
V_25 = - V_56 ;
goto V_57;
}
F_14 ( V_26 , L_18 ,
V_5 -> V_27 , V_5 -> V_28 , V_20 , V_54 ) ;
V_58:
if ( F_36 ( V_59 ) ) {
V_25 = - V_60 ;
goto V_57;
}
F_4 ( & V_5 -> V_8 ) ;
if ( ( V_5 -> V_9 & V_11 ) &&
( V_20 > V_5 -> V_29 ) ) {
F_5 ( & V_5 -> V_8 ) ;
F_6 ( V_5 ) ;
goto V_58;
}
if ( ( V_5 -> V_9 & V_12 ) &&
( ! F_34 ( V_5 , V_20 ) ) ) {
F_5 ( & V_5 -> V_8 ) ;
F_8 ( V_5 ) ;
goto V_58;
}
if ( V_20 > V_5 -> V_29 ) {
V_55 = V_54 | V_52 ;
if ( V_5 -> V_29 != V_32 )
V_55 |= V_51 ;
V_5 -> V_30 = V_20 ;
V_5 -> V_9 |= V_11 ;
F_5 ( & V_5 -> V_8 ) ;
F_27 ( V_20 == V_32 ) ;
F_27 ( V_20 == V_23 ) ;
V_25 = F_32 ( V_48 , V_20 , & V_5 -> V_4 ,
V_55 , V_5 -> V_28 ,
V_5 -> V_27 ) ;
if ( V_25 ) {
if ( ( V_54 & V_61 ) &&
( V_25 != - V_62 ) )
F_31 ( L_16 ,
V_25 , V_5 ) ;
F_11 ( V_5 ) ;
goto V_57;
}
F_6 ( V_5 ) ;
goto V_58;
}
F_33 ( V_5 , V_20 ) ;
F_5 ( & V_5 -> V_8 ) ;
V_25 = 0 ;
V_57:
return V_25 ;
}
static inline void F_37 ( struct V_1 * V_5 ,
int V_20 )
{
switch( V_20 ) {
case V_22 :
F_27 ( ! V_5 -> V_40 ) ;
V_5 -> V_40 -- ;
break;
case V_24 :
F_27 ( ! V_5 -> V_41 ) ;
V_5 -> V_41 -- ;
break;
default:
F_20 () ;
}
}
void F_38 ( struct V_1 * V_5 ,
int V_20 )
{
if ( V_20 != V_22 &&
V_20 != V_24 ) {
F_14 ( V_31 , L_17 ,
V_5 -> V_27 , V_5 -> V_28 ) ;
return;
}
F_4 ( & V_5 -> V_8 ) ;
F_37 ( V_5 , V_20 ) ;
F_24 ( V_5 ) ;
F_5 ( & V_5 -> V_8 ) ;
}
void F_39 ( struct V_18 * V_18 ,
const char * V_63 ,
unsigned int V_64 )
{
struct V_1 * V_5 = & F_40 ( V_18 ) -> V_16 ;
char * V_65 ;
F_27 ( V_64 > V_66 ) ;
F_4 ( & V_5 -> V_8 ) ;
F_27 ( V_5 -> V_29 < V_22 ) ;
V_65 = F_41 ( & V_5 -> V_4 ) ;
memcpy ( V_65 , V_63 , V_64 ) ;
F_5 ( & V_5 -> V_8 ) ;
}
T_1 F_42 ( struct V_18 * V_18 ,
char * V_63 ,
unsigned int V_64 )
{
struct V_1 * V_5 = & F_40 ( V_18 ) -> V_16 ;
char * V_65 ;
T_1 V_7 = V_64 ;
F_27 ( V_64 > V_66 ) ;
F_4 ( & V_5 -> V_8 ) ;
F_27 ( V_5 -> V_29 < V_24 ) ;
if ( F_43 ( & V_5 -> V_4 ) ) {
V_65 = F_41 ( & V_5 -> V_4 ) ;
memcpy ( V_63 , V_65 , V_64 ) ;
} else
V_7 = 0 ;
F_5 ( & V_5 -> V_8 ) ;
return V_7 ;
}
void F_44 ( struct V_1 * V_5 ,
struct V_67 * V_67 )
{
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
F_45 ( & V_5 -> V_8 ) ;
F_46 ( & V_5 -> V_10 ) ;
V_5 -> V_29 = V_32 ;
V_5 -> V_30 = V_32 ;
V_5 -> V_33 = V_32 ;
F_27 ( V_67 -> V_68 . V_64 >= V_69 ) ;
memcpy ( V_5 -> V_28 ,
V_67 -> V_68 . V_70 ,
V_67 -> V_68 . V_64 ) ;
V_5 -> V_27 = V_67 -> V_68 . V_64 ;
}
int F_47 ( struct V_1 * V_5 )
{
int V_25 = - V_71 ;
struct V_13 * V_48 =
F_9 ( V_5 ) ;
F_14 ( V_26 , L_7 , V_5 -> V_27 , V_5 -> V_28 ) ;
F_4 ( & V_5 -> V_8 ) ;
if ( V_5 -> V_9 & V_42 ) {
F_5 ( & V_5 -> V_8 ) ;
return 0 ;
}
V_5 -> V_9 |= V_42 ;
while ( V_5 -> V_9 & V_11 ) {
F_5 ( & V_5 -> V_8 ) ;
F_6 ( V_5 ) ;
F_4 ( & V_5 -> V_8 ) ;
}
if ( V_5 -> V_41 || V_5 -> V_40 ) {
F_5 ( & V_5 -> V_8 ) ;
goto V_57;
}
V_25 = 0 ;
if ( ! ( V_5 -> V_9 & V_34 ) ) {
F_5 ( & V_5 -> V_8 ) ;
goto V_57;
}
V_5 -> V_9 &= ~ V_34 ;
V_5 -> V_9 |= V_11 ;
F_5 ( & V_5 -> V_8 ) ;
V_25 = F_30 ( V_48 , & V_5 -> V_4 , V_52 ) ;
if ( V_25 ) {
F_31 ( L_12 , V_25 , V_5 ) ;
goto V_57;
}
F_6 ( V_5 ) ;
V_25 = 0 ;
V_57:
return V_25 ;
}
static void F_48 ( int V_72 ,
void * V_73 )
{
return;
}
void F_49 ( void )
{
F_50 ( & V_74 . V_75 ) ;
}
struct V_13 * F_51 ( const struct V_76 * V_70 )
{
int V_77 ;
struct V_13 * V_48 ;
V_77 = F_52 ( V_70 -> V_70 , V_70 -> V_64 ,
& V_74 ,
F_48 ,
NULL , & V_48 ) ;
if ( V_77 )
F_53 ( V_77 ) ;
return V_77 ? F_54 ( V_77 ) : V_48 ;
}
void F_55 ( struct V_13 * V_48 )
{
F_56 ( V_48 , 0 ) ;
}
