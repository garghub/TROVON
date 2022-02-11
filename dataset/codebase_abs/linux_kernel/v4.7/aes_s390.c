static int F_1 ( unsigned int V_1 )
{
switch ( V_1 ) {
case 16 :
if ( ! ( V_2 & V_3 ) )
return 1 ;
break;
case 24 :
if ( ! ( V_2 & V_4 ) )
return 1 ;
break;
case 32 :
if ( ! ( V_2 & V_5 ) )
return 1 ;
break;
default:
return - 1 ;
break;
}
return 0 ;
}
static int F_2 ( struct V_6 * V_7 , const T_1 * V_8 ,
unsigned int V_1 )
{
struct V_9 * V_10 = F_3 ( V_7 ) ;
int V_11 ;
V_10 -> V_12 . V_13 -> V_14 . V_15 &= ~ V_16 ;
V_10 -> V_12 . V_13 -> V_14 . V_15 |= ( V_7 -> V_15 &
V_16 ) ;
V_11 = F_4 ( V_10 -> V_12 . V_13 , V_8 , V_1 ) ;
if ( V_11 ) {
V_7 -> V_15 &= ~ V_17 ;
V_7 -> V_15 |= ( V_10 -> V_12 . V_13 -> V_14 . V_15 &
V_17 ) ;
}
return V_11 ;
}
static int F_5 ( struct V_6 * V_7 , const T_1 * V_8 ,
unsigned int V_1 )
{
struct V_9 * V_10 = F_3 ( V_7 ) ;
T_2 * V_18 = & V_7 -> V_15 ;
int V_11 ;
V_11 = F_1 ( V_1 ) ;
if ( V_11 < 0 ) {
* V_18 |= V_19 ;
return - V_20 ;
}
V_10 -> V_1 = V_1 ;
if ( ! V_11 ) {
memcpy ( V_10 -> V_21 , V_8 , V_1 ) ;
return 0 ;
}
return F_2 ( V_7 , V_8 , V_1 ) ;
}
static void F_6 ( struct V_6 * V_7 , T_1 * V_22 , const T_1 * V_23 )
{
struct V_9 * V_10 = F_3 ( V_7 ) ;
if ( F_7 ( F_1 ( V_10 -> V_1 ) ) ) {
F_8 ( V_10 -> V_12 . V_13 , V_22 , V_23 ) ;
return;
}
switch ( V_10 -> V_1 ) {
case 16 :
F_9 ( V_24 , & V_10 -> V_21 , V_22 , V_23 ,
V_25 ) ;
break;
case 24 :
F_9 ( V_26 , & V_10 -> V_21 , V_22 , V_23 ,
V_25 ) ;
break;
case 32 :
F_9 ( V_27 , & V_10 -> V_21 , V_22 , V_23 ,
V_25 ) ;
break;
}
}
static void F_10 ( struct V_6 * V_7 , T_1 * V_22 , const T_1 * V_23 )
{
struct V_9 * V_10 = F_3 ( V_7 ) ;
if ( F_7 ( F_1 ( V_10 -> V_1 ) ) ) {
F_11 ( V_10 -> V_12 . V_13 , V_22 , V_23 ) ;
return;
}
switch ( V_10 -> V_1 ) {
case 16 :
F_9 ( V_28 , & V_10 -> V_21 , V_22 , V_23 ,
V_25 ) ;
break;
case 24 :
F_9 ( V_29 , & V_10 -> V_21 , V_22 , V_23 ,
V_25 ) ;
break;
case 32 :
F_9 ( V_30 , & V_10 -> V_21 , V_22 , V_23 ,
V_25 ) ;
break;
}
}
static int F_12 ( struct V_6 * V_7 )
{
const char * V_31 = V_7 -> V_32 -> V_33 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
V_10 -> V_12 . V_13 = F_13 ( V_31 , 0 ,
V_34 | V_35 ) ;
if ( F_14 ( V_10 -> V_12 . V_13 ) ) {
F_15 ( L_1 ,
V_31 ) ;
return F_16 ( V_10 -> V_12 . V_13 ) ;
}
return 0 ;
}
static void F_17 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = F_3 ( V_7 ) ;
F_18 ( V_10 -> V_12 . V_13 ) ;
V_10 -> V_12 . V_13 = NULL ;
}
static int F_19 ( struct V_6 * V_7 , const T_1 * V_21 ,
unsigned int V_36 )
{
struct V_9 * V_10 = F_3 ( V_7 ) ;
unsigned int V_11 ;
V_10 -> V_12 . V_37 -> V_14 . V_15 &= ~ V_16 ;
V_10 -> V_12 . V_37 -> V_14 . V_15 |= ( V_7 -> V_15 &
V_16 ) ;
V_11 = F_20 ( V_10 -> V_12 . V_37 , V_21 , V_36 ) ;
if ( V_11 ) {
V_7 -> V_15 &= ~ V_17 ;
V_7 -> V_15 |= ( V_10 -> V_12 . V_37 -> V_14 . V_15 &
V_17 ) ;
}
return V_11 ;
}
static int F_21 ( struct V_38 * V_39 ,
struct V_40 * V_41 , struct V_40 * V_42 ,
unsigned int V_43 )
{
unsigned int V_11 ;
struct V_44 * V_7 ;
struct V_9 * V_10 = F_22 ( V_39 -> V_7 ) ;
V_7 = V_39 -> V_7 ;
V_39 -> V_7 = V_10 -> V_12 . V_37 ;
V_11 = F_23 ( V_39 , V_41 , V_42 , V_43 ) ;
V_39 -> V_7 = V_7 ;
return V_11 ;
}
static int F_24 ( struct V_38 * V_39 ,
struct V_40 * V_41 , struct V_40 * V_42 ,
unsigned int V_43 )
{
unsigned int V_11 ;
struct V_44 * V_7 ;
struct V_9 * V_10 = F_22 ( V_39 -> V_7 ) ;
V_7 = V_39 -> V_7 ;
V_39 -> V_7 = V_10 -> V_12 . V_37 ;
V_11 = F_25 ( V_39 , V_41 , V_42 , V_43 ) ;
V_39 -> V_7 = V_7 ;
return V_11 ;
}
static int F_26 ( struct V_6 * V_7 , const T_1 * V_8 ,
unsigned int V_1 )
{
struct V_9 * V_10 = F_3 ( V_7 ) ;
int V_11 ;
V_11 = F_1 ( V_1 ) ;
if ( V_11 > 0 ) {
V_10 -> V_1 = V_1 ;
return F_19 ( V_7 , V_8 , V_1 ) ;
}
switch ( V_1 ) {
case 16 :
V_10 -> V_45 = V_24 ;
V_10 -> V_46 = V_28 ;
break;
case 24 :
V_10 -> V_45 = V_26 ;
V_10 -> V_46 = V_29 ;
break;
case 32 :
V_10 -> V_45 = V_27 ;
V_10 -> V_46 = V_30 ;
break;
}
return F_5 ( V_7 , V_8 , V_1 ) ;
}
static int F_27 ( struct V_38 * V_39 , long V_47 , void * V_48 ,
struct V_49 * V_50 )
{
int V_11 = F_28 ( V_39 , V_50 ) ;
unsigned int V_43 ;
while ( ( V_43 = V_50 -> V_43 ) ) {
unsigned int V_51 = V_43 & ~ ( V_25 - 1 ) ;
T_1 * V_22 = V_50 -> V_41 . V_52 . V_53 ;
T_1 * V_23 = V_50 -> V_42 . V_52 . V_53 ;
V_11 = F_9 ( V_47 , V_48 , V_22 , V_23 , V_51 ) ;
if ( V_11 < 0 || V_11 != V_51 )
return - V_54 ;
V_43 &= V_25 - 1 ;
V_11 = F_29 ( V_39 , V_50 , V_43 ) ;
}
return V_11 ;
}
static int F_30 ( struct V_38 * V_39 ,
struct V_40 * V_41 , struct V_40 * V_42 ,
unsigned int V_43 )
{
struct V_9 * V_10 = F_22 ( V_39 -> V_7 ) ;
struct V_49 V_50 ;
if ( F_7 ( F_1 ( V_10 -> V_1 ) ) )
return F_24 ( V_39 , V_41 , V_42 , V_43 ) ;
F_31 ( & V_50 , V_41 , V_42 , V_43 ) ;
return F_27 ( V_39 , V_10 -> V_45 , V_10 -> V_21 , & V_50 ) ;
}
static int F_32 ( struct V_38 * V_39 ,
struct V_40 * V_41 , struct V_40 * V_42 ,
unsigned int V_43 )
{
struct V_9 * V_10 = F_22 ( V_39 -> V_7 ) ;
struct V_49 V_50 ;
if ( F_7 ( F_1 ( V_10 -> V_1 ) ) )
return F_21 ( V_39 , V_41 , V_42 , V_43 ) ;
F_31 ( & V_50 , V_41 , V_42 , V_43 ) ;
return F_27 ( V_39 , V_10 -> V_46 , V_10 -> V_21 , & V_50 ) ;
}
static int F_33 ( struct V_6 * V_7 )
{
const char * V_31 = V_7 -> V_32 -> V_33 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
V_10 -> V_12 . V_37 = F_34 ( V_31 , 0 ,
V_34 | V_35 ) ;
if ( F_14 ( V_10 -> V_12 . V_37 ) ) {
F_15 ( L_1 ,
V_31 ) ;
return F_16 ( V_10 -> V_12 . V_37 ) ;
}
return 0 ;
}
static void F_35 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = F_3 ( V_7 ) ;
F_36 ( V_10 -> V_12 . V_37 ) ;
V_10 -> V_12 . V_37 = NULL ;
}
static int F_37 ( struct V_6 * V_7 , const T_1 * V_8 ,
unsigned int V_1 )
{
struct V_9 * V_10 = F_3 ( V_7 ) ;
int V_11 ;
V_11 = F_1 ( V_1 ) ;
if ( V_11 > 0 ) {
V_10 -> V_1 = V_1 ;
return F_19 ( V_7 , V_8 , V_1 ) ;
}
switch ( V_1 ) {
case 16 :
V_10 -> V_45 = V_55 ;
V_10 -> V_46 = V_56 ;
break;
case 24 :
V_10 -> V_45 = V_57 ;
V_10 -> V_46 = V_58 ;
break;
case 32 :
V_10 -> V_45 = V_59 ;
V_10 -> V_46 = V_60 ;
break;
}
return F_5 ( V_7 , V_8 , V_1 ) ;
}
static int F_38 ( struct V_38 * V_39 , long V_47 ,
struct V_49 * V_50 )
{
struct V_9 * V_10 = F_22 ( V_39 -> V_7 ) ;
int V_11 = F_28 ( V_39 , V_50 ) ;
unsigned int V_43 = V_50 -> V_43 ;
struct {
T_1 V_61 [ V_25 ] ;
T_1 V_21 [ V_62 ] ;
} V_48 ;
if ( ! V_43 )
goto V_22;
memcpy ( V_48 . V_61 , V_50 -> V_61 , V_25 ) ;
memcpy ( V_48 . V_21 , V_10 -> V_21 , V_10 -> V_1 ) ;
do {
unsigned int V_51 = V_43 & ~ ( V_25 - 1 ) ;
T_1 * V_22 = V_50 -> V_41 . V_52 . V_53 ;
T_1 * V_23 = V_50 -> V_42 . V_52 . V_53 ;
V_11 = F_39 ( V_47 , & V_48 , V_22 , V_23 , V_51 ) ;
if ( V_11 < 0 || V_11 != V_51 )
return - V_54 ;
V_43 &= V_25 - 1 ;
V_11 = F_29 ( V_39 , V_50 , V_43 ) ;
} while ( ( V_43 = V_50 -> V_43 ) );
memcpy ( V_50 -> V_61 , V_48 . V_61 , V_25 ) ;
V_22:
return V_11 ;
}
static int F_40 ( struct V_38 * V_39 ,
struct V_40 * V_41 , struct V_40 * V_42 ,
unsigned int V_43 )
{
struct V_9 * V_10 = F_22 ( V_39 -> V_7 ) ;
struct V_49 V_50 ;
if ( F_7 ( F_1 ( V_10 -> V_1 ) ) )
return F_24 ( V_39 , V_41 , V_42 , V_43 ) ;
F_31 ( & V_50 , V_41 , V_42 , V_43 ) ;
return F_38 ( V_39 , V_10 -> V_45 , & V_50 ) ;
}
static int F_41 ( struct V_38 * V_39 ,
struct V_40 * V_41 , struct V_40 * V_42 ,
unsigned int V_43 )
{
struct V_9 * V_10 = F_22 ( V_39 -> V_7 ) ;
struct V_49 V_50 ;
if ( F_7 ( F_1 ( V_10 -> V_1 ) ) )
return F_21 ( V_39 , V_41 , V_42 , V_43 ) ;
F_31 ( & V_50 , V_41 , V_42 , V_43 ) ;
return F_38 ( V_39 , V_10 -> V_46 , & V_50 ) ;
}
static int F_42 ( struct V_6 * V_7 , const T_1 * V_21 ,
unsigned int V_36 )
{
struct V_63 * V_64 = F_3 ( V_7 ) ;
unsigned int V_11 ;
V_64 -> V_12 -> V_14 . V_15 &= ~ V_16 ;
V_64 -> V_12 -> V_14 . V_15 |= ( V_7 -> V_15 &
V_16 ) ;
V_11 = F_20 ( V_64 -> V_12 , V_21 , V_36 ) ;
if ( V_11 ) {
V_7 -> V_15 &= ~ V_17 ;
V_7 -> V_15 |= ( V_64 -> V_12 -> V_14 . V_15 &
V_17 ) ;
}
return V_11 ;
}
static int F_43 ( struct V_38 * V_39 ,
struct V_40 * V_41 , struct V_40 * V_42 ,
unsigned int V_43 )
{
struct V_63 * V_64 = F_22 ( V_39 -> V_7 ) ;
struct V_44 * V_7 ;
unsigned int V_11 ;
V_7 = V_39 -> V_7 ;
V_39 -> V_7 = V_64 -> V_12 ;
V_11 = F_23 ( V_39 , V_41 , V_42 , V_43 ) ;
V_39 -> V_7 = V_7 ;
return V_11 ;
}
static int F_44 ( struct V_38 * V_39 ,
struct V_40 * V_41 , struct V_40 * V_42 ,
unsigned int V_43 )
{
struct V_63 * V_64 = F_22 ( V_39 -> V_7 ) ;
struct V_44 * V_7 ;
unsigned int V_11 ;
V_7 = V_39 -> V_7 ;
V_39 -> V_7 = V_64 -> V_12 ;
V_11 = F_25 ( V_39 , V_41 , V_42 , V_43 ) ;
V_39 -> V_7 = V_7 ;
return V_11 ;
}
static int F_45 ( struct V_6 * V_7 , const T_1 * V_8 ,
unsigned int V_1 )
{
struct V_63 * V_64 = F_3 ( V_7 ) ;
T_2 * V_18 = & V_7 -> V_15 ;
int V_65 ;
V_65 = F_46 ( V_7 , V_8 , V_1 ) ;
if ( V_65 )
return V_65 ;
switch ( V_1 ) {
case 32 :
V_64 -> V_45 = V_66 ;
V_64 -> V_46 = V_67 ;
memcpy ( V_64 -> V_21 + 16 , V_8 , 16 ) ;
memcpy ( V_64 -> V_68 + 16 , V_8 + 16 , 16 ) ;
break;
case 48 :
V_64 -> V_45 = 0 ;
V_64 -> V_46 = 0 ;
F_42 ( V_7 , V_8 , V_1 ) ;
break;
case 64 :
V_64 -> V_45 = V_69 ;
V_64 -> V_46 = V_70 ;
memcpy ( V_64 -> V_21 , V_8 , 32 ) ;
memcpy ( V_64 -> V_68 , V_8 + 32 , 32 ) ;
break;
default:
* V_18 |= V_19 ;
return - V_20 ;
}
V_64 -> V_1 = V_1 ;
return 0 ;
}
static int F_47 ( struct V_38 * V_39 , long V_47 ,
struct V_63 * V_64 ,
struct V_49 * V_50 )
{
unsigned int V_71 = ( V_64 -> V_1 >> 1 ) & 0x10 ;
int V_11 = F_28 ( V_39 , V_50 ) ;
unsigned int V_43 = V_50 -> V_43 ;
unsigned int V_51 ;
T_1 * V_23 , * V_22 ;
struct V_72 V_72 ;
struct {
T_1 V_21 [ 32 ] ;
T_1 V_73 [ 16 ] ;
} V_74 ;
if ( ! V_43 )
goto V_22;
memset ( V_72 . V_75 , 0 , sizeof( V_72 . V_75 ) ) ;
memset ( V_72 . V_76 , 0 , sizeof( V_72 . V_76 ) ) ;
memset ( V_72 . V_77 , 0 , sizeof( V_72 . V_77 ) ) ;
memcpy ( V_72 . V_78 , V_50 -> V_61 , sizeof( V_72 . V_78 ) ) ;
memcpy ( V_72 . V_21 , V_64 -> V_68 , 32 ) ;
V_11 = F_48 ( V_47 & 0x7f , & V_72 . V_21 [ V_71 ] ) ;
if ( V_11 < 0 )
return - V_54 ;
memcpy ( V_74 . V_21 , V_64 -> V_21 , 32 ) ;
memcpy ( V_74 . V_73 , V_72 . V_77 , 16 ) ;
do {
V_51 = V_43 & ~ ( V_25 - 1 ) ;
V_22 = V_50 -> V_41 . V_52 . V_53 ;
V_23 = V_50 -> V_42 . V_52 . V_53 ;
V_11 = F_9 ( V_47 , & V_74 . V_21 [ V_71 ] , V_22 , V_23 , V_51 ) ;
if ( V_11 < 0 || V_11 != V_51 )
return - V_54 ;
V_43 &= V_25 - 1 ;
V_11 = F_29 ( V_39 , V_50 , V_43 ) ;
} while ( ( V_43 = V_50 -> V_43 ) );
V_22:
return V_11 ;
}
static int F_49 ( struct V_38 * V_39 ,
struct V_40 * V_41 , struct V_40 * V_42 ,
unsigned int V_43 )
{
struct V_63 * V_64 = F_22 ( V_39 -> V_7 ) ;
struct V_49 V_50 ;
if ( F_7 ( V_64 -> V_1 == 48 ) )
return F_44 ( V_39 , V_41 , V_42 , V_43 ) ;
F_31 ( & V_50 , V_41 , V_42 , V_43 ) ;
return F_47 ( V_39 , V_64 -> V_45 , V_64 , & V_50 ) ;
}
static int F_50 ( struct V_38 * V_39 ,
struct V_40 * V_41 , struct V_40 * V_42 ,
unsigned int V_43 )
{
struct V_63 * V_64 = F_22 ( V_39 -> V_7 ) ;
struct V_49 V_50 ;
if ( F_7 ( V_64 -> V_1 == 48 ) )
return F_43 ( V_39 , V_41 , V_42 , V_43 ) ;
F_31 ( & V_50 , V_41 , V_42 , V_43 ) ;
return F_47 ( V_39 , V_64 -> V_46 , V_64 , & V_50 ) ;
}
static int F_51 ( struct V_6 * V_7 )
{
const char * V_31 = V_7 -> V_32 -> V_33 ;
struct V_63 * V_64 = F_3 ( V_7 ) ;
V_64 -> V_12 = F_34 ( V_31 , 0 ,
V_34 | V_35 ) ;
if ( F_14 ( V_64 -> V_12 ) ) {
F_15 ( L_2 ,
V_31 ) ;
return F_16 ( V_64 -> V_12 ) ;
}
return 0 ;
}
static void F_52 ( struct V_6 * V_7 )
{
struct V_63 * V_64 = F_3 ( V_7 ) ;
F_36 ( V_64 -> V_12 ) ;
V_64 -> V_12 = NULL ;
}
static int F_53 ( struct V_6 * V_7 , const T_1 * V_8 ,
unsigned int V_1 )
{
struct V_9 * V_10 = F_3 ( V_7 ) ;
switch ( V_1 ) {
case 16 :
V_10 -> V_45 = V_79 ;
V_10 -> V_46 = V_80 ;
break;
case 24 :
V_10 -> V_45 = V_81 ;
V_10 -> V_46 = V_82 ;
break;
case 32 :
V_10 -> V_45 = V_83 ;
V_10 -> V_46 = V_84 ;
break;
}
return F_5 ( V_7 , V_8 , V_1 ) ;
}
static unsigned int F_54 ( T_1 * V_85 , unsigned int V_43 )
{
unsigned int V_86 , V_51 ;
V_51 = ( V_43 > V_87 ) ? V_87 : V_43 & ~ ( V_25 - 1 ) ;
for ( V_86 = V_25 ; V_86 < V_51 ; V_86 += V_25 ) {
memcpy ( V_85 + V_86 , V_85 + V_86 - V_25 ,
V_25 ) ;
F_55 ( V_85 + V_86 , V_25 ) ;
}
return V_51 ;
}
static int F_56 ( struct V_38 * V_39 , long V_47 ,
struct V_9 * V_10 , struct V_49 * V_50 )
{
int V_11 = F_57 ( V_39 , V_50 , V_25 ) ;
unsigned int V_51 , V_43 ;
T_1 V_88 [ V_25 ] , V_89 [ V_25 ] ;
T_1 * V_22 , * V_23 , * V_85 = V_89 ;
if ( ! V_50 -> V_43 )
return V_11 ;
if ( F_58 ( & V_90 ) )
V_85 = V_91 ;
memcpy ( V_85 , V_50 -> V_61 , V_25 ) ;
while ( ( V_43 = V_50 -> V_43 ) >= V_25 ) {
V_22 = V_50 -> V_41 . V_52 . V_53 ;
V_23 = V_50 -> V_42 . V_52 . V_53 ;
while ( V_43 >= V_25 ) {
if ( V_85 == V_91 )
V_51 = F_54 ( V_85 , V_43 ) ;
else
V_51 = V_25 ;
V_11 = F_59 ( V_47 , V_10 -> V_21 , V_22 , V_23 , V_51 , V_85 ) ;
if ( V_11 < 0 || V_11 != V_51 ) {
if ( V_85 == V_91 )
F_60 ( & V_90 ) ;
return - V_54 ;
}
if ( V_51 > V_25 )
memcpy ( V_85 , V_85 + V_51 - V_25 ,
V_25 ) ;
F_55 ( V_85 , V_25 ) ;
V_22 += V_51 ;
V_23 += V_51 ;
V_43 -= V_51 ;
}
V_11 = F_29 ( V_39 , V_50 , V_43 ) ;
}
if ( V_85 == V_91 ) {
if ( V_43 )
memcpy ( V_89 , V_85 , V_25 ) ;
else
memcpy ( V_50 -> V_61 , V_85 , V_25 ) ;
F_60 ( & V_90 ) ;
} else {
if ( ! V_43 )
memcpy ( V_50 -> V_61 , V_85 , V_25 ) ;
}
if ( V_43 ) {
V_22 = V_50 -> V_41 . V_52 . V_53 ;
V_23 = V_50 -> V_42 . V_52 . V_53 ;
V_11 = F_59 ( V_47 , V_10 -> V_21 , V_88 , V_23 ,
V_25 , V_89 ) ;
if ( V_11 < 0 || V_11 != V_25 )
return - V_54 ;
memcpy ( V_22 , V_88 , V_43 ) ;
F_55 ( V_89 , V_25 ) ;
V_11 = F_29 ( V_39 , V_50 , 0 ) ;
memcpy ( V_50 -> V_61 , V_89 , V_25 ) ;
}
return V_11 ;
}
static int F_61 ( struct V_38 * V_39 ,
struct V_40 * V_41 , struct V_40 * V_42 ,
unsigned int V_43 )
{
struct V_9 * V_10 = F_22 ( V_39 -> V_7 ) ;
struct V_49 V_50 ;
F_31 ( & V_50 , V_41 , V_42 , V_43 ) ;
return F_56 ( V_39 , V_10 -> V_45 , V_10 , & V_50 ) ;
}
static int F_62 ( struct V_38 * V_39 ,
struct V_40 * V_41 , struct V_40 * V_42 ,
unsigned int V_43 )
{
struct V_9 * V_10 = F_22 ( V_39 -> V_7 ) ;
struct V_49 V_50 ;
F_31 ( & V_50 , V_41 , V_42 , V_43 ) ;
return F_56 ( V_39 , V_10 -> V_46 , V_10 , & V_50 ) ;
}
static int T_3 F_63 ( void )
{
int V_11 ;
if ( F_64 ( V_92 , V_24 ) )
V_2 |= V_3 ;
if ( F_64 ( V_92 , V_26 ) )
V_2 |= V_4 ;
if ( F_64 ( V_92 , V_27 ) )
V_2 |= V_5 ;
if ( ! V_2 )
return - V_93 ;
if ( V_2 == V_3 )
F_65 ( L_3
L_4 ) ;
V_11 = F_66 ( & V_94 ) ;
if ( V_11 )
goto V_95;
V_11 = F_66 ( & V_96 ) ;
if ( V_11 )
goto V_97;
V_11 = F_66 ( & V_98 ) ;
if ( V_11 )
goto V_99;
if ( F_64 ( V_92 , V_66 ) &&
F_64 ( V_92 , V_69 ) ) {
V_11 = F_66 ( & V_100 ) ;
if ( V_11 )
goto V_101;
V_102 = 1 ;
}
if ( F_64 ( V_103 , V_79 ) &&
F_64 ( V_103 , V_81 ) &&
F_64 ( V_103 , V_83 ) ) {
V_91 = ( T_1 * ) F_67 ( V_104 ) ;
if ( ! V_91 ) {
V_11 = - V_105 ;
goto V_106;
}
V_11 = F_66 ( & V_107 ) ;
if ( V_11 ) {
F_68 ( ( unsigned long ) V_91 ) ;
goto V_106;
}
V_108 = 1 ;
}
V_22:
return V_11 ;
V_106:
F_69 ( & V_100 ) ;
V_101:
F_69 ( & V_98 ) ;
V_99:
F_69 ( & V_96 ) ;
V_97:
F_69 ( & V_94 ) ;
V_95:
goto V_22;
}
static void T_4 F_70 ( void )
{
if ( V_108 ) {
F_69 ( & V_107 ) ;
F_68 ( ( unsigned long ) V_91 ) ;
}
if ( V_102 )
F_69 ( & V_100 ) ;
F_69 ( & V_98 ) ;
F_69 ( & V_96 ) ;
F_69 ( & V_94 ) ;
}
