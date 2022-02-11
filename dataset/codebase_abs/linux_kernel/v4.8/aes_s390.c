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
F_20 ( V_10 -> V_12 . V_37 , V_16 ) ;
F_21 ( V_10 -> V_12 . V_37 , V_7 -> V_15 &
V_16 ) ;
V_11 = F_22 ( V_10 -> V_12 . V_37 , V_21 , V_36 ) ;
V_7 -> V_15 &= ~ V_17 ;
V_7 -> V_15 |= F_23 ( V_10 -> V_12 . V_37 ) &
V_17 ;
return V_11 ;
}
static int F_24 ( struct V_38 * V_39 ,
struct V_40 * V_41 , struct V_40 * V_42 ,
unsigned int V_43 )
{
unsigned int V_11 ;
struct V_44 * V_7 = V_39 -> V_7 ;
struct V_9 * V_10 = F_25 ( V_7 ) ;
F_26 ( V_45 , V_10 -> V_12 . V_37 ) ;
F_27 ( V_45 , V_10 -> V_12 . V_37 ) ;
F_28 ( V_45 , V_39 -> V_18 , NULL , NULL ) ;
F_29 ( V_45 , V_42 , V_41 , V_43 , V_39 -> V_46 ) ;
V_11 = F_30 ( V_45 ) ;
F_31 ( V_45 ) ;
return V_11 ;
}
static int F_32 ( struct V_38 * V_39 ,
struct V_40 * V_41 , struct V_40 * V_42 ,
unsigned int V_43 )
{
unsigned int V_11 ;
struct V_44 * V_7 = V_39 -> V_7 ;
struct V_9 * V_10 = F_25 ( V_7 ) ;
F_26 ( V_45 , V_10 -> V_12 . V_37 ) ;
F_27 ( V_45 , V_10 -> V_12 . V_37 ) ;
F_28 ( V_45 , V_39 -> V_18 , NULL , NULL ) ;
F_29 ( V_45 , V_42 , V_41 , V_43 , V_39 -> V_46 ) ;
V_11 = F_33 ( V_45 ) ;
return V_11 ;
}
static int F_34 ( struct V_6 * V_7 , const T_1 * V_8 ,
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
V_10 -> V_47 = V_24 ;
V_10 -> V_48 = V_28 ;
break;
case 24 :
V_10 -> V_47 = V_26 ;
V_10 -> V_48 = V_29 ;
break;
case 32 :
V_10 -> V_47 = V_27 ;
V_10 -> V_48 = V_30 ;
break;
}
return F_5 ( V_7 , V_8 , V_1 ) ;
}
static int F_35 ( struct V_38 * V_39 , long V_49 , void * V_50 ,
struct V_51 * V_52 )
{
int V_11 = F_36 ( V_39 , V_52 ) ;
unsigned int V_43 ;
while ( ( V_43 = V_52 -> V_43 ) ) {
unsigned int V_53 = V_43 & ~ ( V_25 - 1 ) ;
T_1 * V_22 = V_52 -> V_41 . V_54 . V_55 ;
T_1 * V_23 = V_52 -> V_42 . V_54 . V_55 ;
V_11 = F_9 ( V_49 , V_50 , V_22 , V_23 , V_53 ) ;
if ( V_11 < 0 || V_11 != V_53 )
return - V_56 ;
V_43 &= V_25 - 1 ;
V_11 = F_37 ( V_39 , V_52 , V_43 ) ;
}
return V_11 ;
}
static int F_38 ( struct V_38 * V_39 ,
struct V_40 * V_41 , struct V_40 * V_42 ,
unsigned int V_43 )
{
struct V_9 * V_10 = F_25 ( V_39 -> V_7 ) ;
struct V_51 V_52 ;
if ( F_7 ( F_1 ( V_10 -> V_1 ) ) )
return F_32 ( V_39 , V_41 , V_42 , V_43 ) ;
F_39 ( & V_52 , V_41 , V_42 , V_43 ) ;
return F_35 ( V_39 , V_10 -> V_47 , V_10 -> V_21 , & V_52 ) ;
}
static int F_40 ( struct V_38 * V_39 ,
struct V_40 * V_41 , struct V_40 * V_42 ,
unsigned int V_43 )
{
struct V_9 * V_10 = F_25 ( V_39 -> V_7 ) ;
struct V_51 V_52 ;
if ( F_7 ( F_1 ( V_10 -> V_1 ) ) )
return F_24 ( V_39 , V_41 , V_42 , V_43 ) ;
F_39 ( & V_52 , V_41 , V_42 , V_43 ) ;
return F_35 ( V_39 , V_10 -> V_48 , V_10 -> V_21 , & V_52 ) ;
}
static int F_41 ( struct V_6 * V_7 )
{
const char * V_31 = V_7 -> V_32 -> V_33 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
V_10 -> V_12 . V_37 = F_42 ( V_31 , 0 ,
V_34 |
V_35 ) ;
if ( F_14 ( V_10 -> V_12 . V_37 ) ) {
F_15 ( L_1 ,
V_31 ) ;
return F_16 ( V_10 -> V_12 . V_37 ) ;
}
return 0 ;
}
static void F_43 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = F_3 ( V_7 ) ;
F_44 ( V_10 -> V_12 . V_37 ) ;
}
static int F_45 ( struct V_6 * V_7 , const T_1 * V_8 ,
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
V_10 -> V_47 = V_57 ;
V_10 -> V_48 = V_58 ;
break;
case 24 :
V_10 -> V_47 = V_59 ;
V_10 -> V_48 = V_60 ;
break;
case 32 :
V_10 -> V_47 = V_61 ;
V_10 -> V_48 = V_62 ;
break;
}
return F_5 ( V_7 , V_8 , V_1 ) ;
}
static int F_46 ( struct V_38 * V_39 , long V_49 ,
struct V_51 * V_52 )
{
struct V_9 * V_10 = F_25 ( V_39 -> V_7 ) ;
int V_11 = F_36 ( V_39 , V_52 ) ;
unsigned int V_43 = V_52 -> V_43 ;
struct {
T_1 V_63 [ V_25 ] ;
T_1 V_21 [ V_64 ] ;
} V_50 ;
if ( ! V_43 )
goto V_22;
memcpy ( V_50 . V_63 , V_52 -> V_63 , V_25 ) ;
memcpy ( V_50 . V_21 , V_10 -> V_21 , V_10 -> V_1 ) ;
do {
unsigned int V_53 = V_43 & ~ ( V_25 - 1 ) ;
T_1 * V_22 = V_52 -> V_41 . V_54 . V_55 ;
T_1 * V_23 = V_52 -> V_42 . V_54 . V_55 ;
V_11 = F_47 ( V_49 , & V_50 , V_22 , V_23 , V_53 ) ;
if ( V_11 < 0 || V_11 != V_53 )
return - V_56 ;
V_43 &= V_25 - 1 ;
V_11 = F_37 ( V_39 , V_52 , V_43 ) ;
} while ( ( V_43 = V_52 -> V_43 ) );
memcpy ( V_52 -> V_63 , V_50 . V_63 , V_25 ) ;
V_22:
return V_11 ;
}
static int F_48 ( struct V_38 * V_39 ,
struct V_40 * V_41 , struct V_40 * V_42 ,
unsigned int V_43 )
{
struct V_9 * V_10 = F_25 ( V_39 -> V_7 ) ;
struct V_51 V_52 ;
if ( F_7 ( F_1 ( V_10 -> V_1 ) ) )
return F_32 ( V_39 , V_41 , V_42 , V_43 ) ;
F_39 ( & V_52 , V_41 , V_42 , V_43 ) ;
return F_46 ( V_39 , V_10 -> V_47 , & V_52 ) ;
}
static int F_49 ( struct V_38 * V_39 ,
struct V_40 * V_41 , struct V_40 * V_42 ,
unsigned int V_43 )
{
struct V_9 * V_10 = F_25 ( V_39 -> V_7 ) ;
struct V_51 V_52 ;
if ( F_7 ( F_1 ( V_10 -> V_1 ) ) )
return F_24 ( V_39 , V_41 , V_42 , V_43 ) ;
F_39 ( & V_52 , V_41 , V_42 , V_43 ) ;
return F_46 ( V_39 , V_10 -> V_48 , & V_52 ) ;
}
static int F_50 ( struct V_6 * V_7 , const T_1 * V_21 ,
unsigned int V_36 )
{
struct V_65 * V_66 = F_3 ( V_7 ) ;
unsigned int V_11 ;
F_20 ( V_66 -> V_12 , V_16 ) ;
F_21 ( V_66 -> V_12 , V_7 -> V_15 &
V_16 ) ;
V_11 = F_22 ( V_66 -> V_12 , V_21 , V_36 ) ;
V_7 -> V_15 &= ~ V_17 ;
V_7 -> V_15 |= F_23 ( V_66 -> V_12 ) &
V_17 ;
return V_11 ;
}
static int F_51 ( struct V_38 * V_39 ,
struct V_40 * V_41 , struct V_40 * V_42 ,
unsigned int V_43 )
{
struct V_44 * V_7 = V_39 -> V_7 ;
struct V_65 * V_66 = F_25 ( V_7 ) ;
F_26 ( V_45 , V_66 -> V_12 ) ;
unsigned int V_11 ;
F_27 ( V_45 , V_66 -> V_12 ) ;
F_28 ( V_45 , V_39 -> V_18 , NULL , NULL ) ;
F_29 ( V_45 , V_42 , V_41 , V_43 , V_39 -> V_46 ) ;
V_11 = F_30 ( V_45 ) ;
F_31 ( V_45 ) ;
return V_11 ;
}
static int F_52 ( struct V_38 * V_39 ,
struct V_40 * V_41 , struct V_40 * V_42 ,
unsigned int V_43 )
{
struct V_44 * V_7 = V_39 -> V_7 ;
struct V_65 * V_66 = F_25 ( V_7 ) ;
F_26 ( V_45 , V_66 -> V_12 ) ;
unsigned int V_11 ;
F_27 ( V_45 , V_66 -> V_12 ) ;
F_28 ( V_45 , V_39 -> V_18 , NULL , NULL ) ;
F_29 ( V_45 , V_42 , V_41 , V_43 , V_39 -> V_46 ) ;
V_11 = F_33 ( V_45 ) ;
F_31 ( V_45 ) ;
return V_11 ;
}
static int F_53 ( struct V_6 * V_7 , const T_1 * V_8 ,
unsigned int V_1 )
{
struct V_65 * V_66 = F_3 ( V_7 ) ;
T_2 * V_18 = & V_7 -> V_15 ;
int V_67 ;
V_67 = F_54 ( V_7 , V_8 , V_1 ) ;
if ( V_67 )
return V_67 ;
switch ( V_1 ) {
case 32 :
V_66 -> V_47 = V_68 ;
V_66 -> V_48 = V_69 ;
memcpy ( V_66 -> V_21 + 16 , V_8 , 16 ) ;
memcpy ( V_66 -> V_70 + 16 , V_8 + 16 , 16 ) ;
break;
case 48 :
V_66 -> V_47 = 0 ;
V_66 -> V_48 = 0 ;
F_50 ( V_7 , V_8 , V_1 ) ;
break;
case 64 :
V_66 -> V_47 = V_71 ;
V_66 -> V_48 = V_72 ;
memcpy ( V_66 -> V_21 , V_8 , 32 ) ;
memcpy ( V_66 -> V_70 , V_8 + 32 , 32 ) ;
break;
default:
* V_18 |= V_19 ;
return - V_20 ;
}
V_66 -> V_1 = V_1 ;
return 0 ;
}
static int F_55 ( struct V_38 * V_39 , long V_49 ,
struct V_65 * V_66 ,
struct V_51 * V_52 )
{
unsigned int V_73 = ( V_66 -> V_1 >> 1 ) & 0x10 ;
int V_11 = F_36 ( V_39 , V_52 ) ;
unsigned int V_43 = V_52 -> V_43 ;
unsigned int V_53 ;
T_1 * V_23 , * V_22 ;
struct V_74 V_74 ;
struct {
T_1 V_21 [ 32 ] ;
T_1 V_75 [ 16 ] ;
} V_76 ;
if ( ! V_43 )
goto V_22;
memset ( V_74 . V_77 , 0 , sizeof( V_74 . V_77 ) ) ;
memset ( V_74 . V_78 , 0 , sizeof( V_74 . V_78 ) ) ;
memset ( V_74 . V_79 , 0 , sizeof( V_74 . V_79 ) ) ;
memcpy ( V_74 . V_80 , V_52 -> V_63 , sizeof( V_74 . V_80 ) ) ;
memcpy ( V_74 . V_21 , V_66 -> V_70 , 32 ) ;
V_11 = F_56 ( V_49 & 0x7f , & V_74 . V_21 [ V_73 ] ) ;
if ( V_11 < 0 )
return - V_56 ;
memcpy ( V_76 . V_21 , V_66 -> V_21 , 32 ) ;
memcpy ( V_76 . V_75 , V_74 . V_79 , 16 ) ;
do {
V_53 = V_43 & ~ ( V_25 - 1 ) ;
V_22 = V_52 -> V_41 . V_54 . V_55 ;
V_23 = V_52 -> V_42 . V_54 . V_55 ;
V_11 = F_9 ( V_49 , & V_76 . V_21 [ V_73 ] , V_22 , V_23 , V_53 ) ;
if ( V_11 < 0 || V_11 != V_53 )
return - V_56 ;
V_43 &= V_25 - 1 ;
V_11 = F_37 ( V_39 , V_52 , V_43 ) ;
} while ( ( V_43 = V_52 -> V_43 ) );
V_22:
return V_11 ;
}
static int F_57 ( struct V_38 * V_39 ,
struct V_40 * V_41 , struct V_40 * V_42 ,
unsigned int V_43 )
{
struct V_65 * V_66 = F_25 ( V_39 -> V_7 ) ;
struct V_51 V_52 ;
if ( F_7 ( V_66 -> V_1 == 48 ) )
return F_52 ( V_39 , V_41 , V_42 , V_43 ) ;
F_39 ( & V_52 , V_41 , V_42 , V_43 ) ;
return F_55 ( V_39 , V_66 -> V_47 , V_66 , & V_52 ) ;
}
static int F_58 ( struct V_38 * V_39 ,
struct V_40 * V_41 , struct V_40 * V_42 ,
unsigned int V_43 )
{
struct V_65 * V_66 = F_25 ( V_39 -> V_7 ) ;
struct V_51 V_52 ;
if ( F_7 ( V_66 -> V_1 == 48 ) )
return F_51 ( V_39 , V_41 , V_42 , V_43 ) ;
F_39 ( & V_52 , V_41 , V_42 , V_43 ) ;
return F_55 ( V_39 , V_66 -> V_48 , V_66 , & V_52 ) ;
}
static int F_59 ( struct V_6 * V_7 )
{
const char * V_31 = V_7 -> V_32 -> V_33 ;
struct V_65 * V_66 = F_3 ( V_7 ) ;
V_66 -> V_12 = F_42 ( V_31 , 0 ,
V_34 |
V_35 ) ;
if ( F_14 ( V_66 -> V_12 ) ) {
F_15 ( L_2 ,
V_31 ) ;
return F_16 ( V_66 -> V_12 ) ;
}
return 0 ;
}
static void F_60 ( struct V_6 * V_7 )
{
struct V_65 * V_66 = F_3 ( V_7 ) ;
F_44 ( V_66 -> V_12 ) ;
}
static int F_61 ( struct V_6 * V_7 , const T_1 * V_8 ,
unsigned int V_1 )
{
struct V_9 * V_10 = F_3 ( V_7 ) ;
switch ( V_1 ) {
case 16 :
V_10 -> V_47 = V_81 ;
V_10 -> V_48 = V_82 ;
break;
case 24 :
V_10 -> V_47 = V_83 ;
V_10 -> V_48 = V_84 ;
break;
case 32 :
V_10 -> V_47 = V_85 ;
V_10 -> V_48 = V_86 ;
break;
}
return F_5 ( V_7 , V_8 , V_1 ) ;
}
static unsigned int F_62 ( T_1 * V_87 , unsigned int V_43 )
{
unsigned int V_88 , V_53 ;
V_53 = ( V_43 > V_89 ) ? V_89 : V_43 & ~ ( V_25 - 1 ) ;
for ( V_88 = V_25 ; V_88 < V_53 ; V_88 += V_25 ) {
memcpy ( V_87 + V_88 , V_87 + V_88 - V_25 ,
V_25 ) ;
F_63 ( V_87 + V_88 , V_25 ) ;
}
return V_53 ;
}
static int F_64 ( struct V_38 * V_39 , long V_49 ,
struct V_9 * V_10 , struct V_51 * V_52 )
{
int V_11 = F_65 ( V_39 , V_52 , V_25 ) ;
unsigned int V_53 , V_43 ;
T_1 V_90 [ V_25 ] , V_91 [ V_25 ] ;
T_1 * V_22 , * V_23 , * V_87 = V_91 ;
if ( ! V_52 -> V_43 )
return V_11 ;
if ( F_66 ( & V_92 ) )
V_87 = V_93 ;
memcpy ( V_87 , V_52 -> V_63 , V_25 ) ;
while ( ( V_43 = V_52 -> V_43 ) >= V_25 ) {
V_22 = V_52 -> V_41 . V_54 . V_55 ;
V_23 = V_52 -> V_42 . V_54 . V_55 ;
while ( V_43 >= V_25 ) {
if ( V_87 == V_93 )
V_53 = F_62 ( V_87 , V_43 ) ;
else
V_53 = V_25 ;
V_11 = F_67 ( V_49 , V_10 -> V_21 , V_22 , V_23 , V_53 , V_87 ) ;
if ( V_11 < 0 || V_11 != V_53 ) {
if ( V_87 == V_93 )
F_68 ( & V_92 ) ;
return - V_56 ;
}
if ( V_53 > V_25 )
memcpy ( V_87 , V_87 + V_53 - V_25 ,
V_25 ) ;
F_63 ( V_87 , V_25 ) ;
V_22 += V_53 ;
V_23 += V_53 ;
V_43 -= V_53 ;
}
V_11 = F_37 ( V_39 , V_52 , V_43 ) ;
}
if ( V_87 == V_93 ) {
if ( V_43 )
memcpy ( V_91 , V_87 , V_25 ) ;
else
memcpy ( V_52 -> V_63 , V_87 , V_25 ) ;
F_68 ( & V_92 ) ;
} else {
if ( ! V_43 )
memcpy ( V_52 -> V_63 , V_87 , V_25 ) ;
}
if ( V_43 ) {
V_22 = V_52 -> V_41 . V_54 . V_55 ;
V_23 = V_52 -> V_42 . V_54 . V_55 ;
V_11 = F_67 ( V_49 , V_10 -> V_21 , V_90 , V_23 ,
V_25 , V_91 ) ;
if ( V_11 < 0 || V_11 != V_25 )
return - V_56 ;
memcpy ( V_22 , V_90 , V_43 ) ;
F_63 ( V_91 , V_25 ) ;
V_11 = F_37 ( V_39 , V_52 , 0 ) ;
memcpy ( V_52 -> V_63 , V_91 , V_25 ) ;
}
return V_11 ;
}
static int F_69 ( struct V_38 * V_39 ,
struct V_40 * V_41 , struct V_40 * V_42 ,
unsigned int V_43 )
{
struct V_9 * V_10 = F_25 ( V_39 -> V_7 ) ;
struct V_51 V_52 ;
F_39 ( & V_52 , V_41 , V_42 , V_43 ) ;
return F_64 ( V_39 , V_10 -> V_47 , V_10 , & V_52 ) ;
}
static int F_70 ( struct V_38 * V_39 ,
struct V_40 * V_41 , struct V_40 * V_42 ,
unsigned int V_43 )
{
struct V_9 * V_10 = F_25 ( V_39 -> V_7 ) ;
struct V_51 V_52 ;
F_39 ( & V_52 , V_41 , V_42 , V_43 ) ;
return F_64 ( V_39 , V_10 -> V_48 , V_10 , & V_52 ) ;
}
static int T_3 F_71 ( void )
{
int V_11 ;
if ( F_72 ( V_94 , V_24 ) )
V_2 |= V_3 ;
if ( F_72 ( V_94 , V_26 ) )
V_2 |= V_4 ;
if ( F_72 ( V_94 , V_27 ) )
V_2 |= V_5 ;
if ( ! V_2 )
return - V_95 ;
if ( V_2 == V_3 )
F_73 ( L_3
L_4 ) ;
V_11 = F_74 ( & V_96 ) ;
if ( V_11 )
goto V_97;
V_11 = F_74 ( & V_98 ) ;
if ( V_11 )
goto V_99;
V_11 = F_74 ( & V_100 ) ;
if ( V_11 )
goto V_101;
if ( F_72 ( V_94 , V_68 ) &&
F_72 ( V_94 , V_71 ) ) {
V_11 = F_74 ( & V_102 ) ;
if ( V_11 )
goto V_103;
V_104 = 1 ;
}
if ( F_72 ( V_105 , V_81 ) &&
F_72 ( V_105 , V_83 ) &&
F_72 ( V_105 , V_85 ) ) {
V_93 = ( T_1 * ) F_75 ( V_106 ) ;
if ( ! V_93 ) {
V_11 = - V_107 ;
goto V_108;
}
V_11 = F_74 ( & V_109 ) ;
if ( V_11 ) {
F_76 ( ( unsigned long ) V_93 ) ;
goto V_108;
}
V_110 = 1 ;
}
V_22:
return V_11 ;
V_108:
F_77 ( & V_102 ) ;
V_103:
F_77 ( & V_100 ) ;
V_101:
F_77 ( & V_98 ) ;
V_99:
F_77 ( & V_96 ) ;
V_97:
goto V_22;
}
static void T_4 F_78 ( void )
{
if ( V_110 ) {
F_77 ( & V_109 ) ;
F_76 ( ( unsigned long ) V_93 ) ;
}
if ( V_104 )
F_77 ( & V_102 ) ;
F_77 ( & V_100 ) ;
F_77 ( & V_98 ) ;
F_77 ( & V_96 ) ;
}
