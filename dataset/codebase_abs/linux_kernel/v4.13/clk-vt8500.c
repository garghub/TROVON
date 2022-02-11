static T_1 void F_1 ( void )
{
struct V_1 * V_2 =
F_2 ( NULL , NULL , L_1 ) ;
if ( V_2 )
V_3 = F_3 ( V_2 , 0 ) ;
else
V_3 = F_4 ( V_4 , 0x1000 ) ;
F_5 ( V_2 ) ;
if ( ! V_3 )
F_6 ( L_2 , V_5 ) ;
}
static void F_7 ( void )
{
while ( F_8 ( V_3 ) & V_6 )
F_9 () ;
}
static int F_10 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_11 ( V_8 ) ;
T_2 V_11 ;
unsigned long V_12 = 0 ;
F_12 ( V_10 -> V_13 , V_12 ) ;
V_11 = F_8 ( V_10 -> V_14 ) ;
V_11 |= F_13 ( V_10 -> V_15 ) ;
F_14 ( V_11 , V_10 -> V_14 ) ;
F_15 ( V_10 -> V_13 , V_12 ) ;
return 0 ;
}
static void F_16 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_11 ( V_8 ) ;
T_2 V_11 ;
unsigned long V_12 = 0 ;
F_12 ( V_10 -> V_13 , V_12 ) ;
V_11 = F_8 ( V_10 -> V_14 ) ;
V_11 &= ~ F_13 ( V_10 -> V_15 ) ;
F_14 ( V_11 , V_10 -> V_14 ) ;
F_15 ( V_10 -> V_13 , V_12 ) ;
}
static int F_17 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_11 ( V_8 ) ;
T_2 V_11 = ( F_8 ( V_10 -> V_14 ) & F_13 ( V_10 -> V_15 ) ) ;
return V_11 ? 1 : 0 ;
}
static unsigned long F_18 ( struct V_7 * V_8 ,
unsigned long V_16 )
{
struct V_9 * V_10 = F_11 ( V_8 ) ;
T_2 div = F_8 ( V_10 -> V_17 ) & V_10 -> V_18 ;
if ( ( V_10 -> V_18 == 0x3F ) && ( div & F_13 ( 5 ) ) )
div = 64 * ( div & 0x1f ) ;
if ( div == 0 )
div = ( V_10 -> V_18 + 1 ) ;
return V_16 / div ;
}
static long F_19 ( struct V_7 * V_8 , unsigned long V_19 ,
unsigned long * V_20 )
{
struct V_9 * V_10 = F_11 ( V_8 ) ;
T_2 V_21 ;
if ( V_19 == 0 )
return 0 ;
V_21 = * V_20 / V_19 ;
if ( V_19 * V_21 < * V_20 )
V_21 ++ ;
if ( ( V_10 -> V_18 == 0x3F ) && ( V_21 > 31 ) ) {
V_21 = 64 * ( ( V_21 / 64 ) + 1 ) ;
}
return * V_20 / V_21 ;
}
static int F_20 ( struct V_7 * V_8 , unsigned long V_19 ,
unsigned long V_16 )
{
struct V_9 * V_10 = F_11 ( V_8 ) ;
T_2 V_21 ;
unsigned long V_12 = 0 ;
if ( V_19 == 0 )
return 0 ;
V_21 = V_16 / V_19 ;
if ( V_21 == V_10 -> V_18 + 1 )
V_21 = 0 ;
if ( ( V_10 -> V_18 == 0x3F ) && ( V_21 > 31 ) ) {
V_21 = 0x20 + ( V_21 / 64 ) ;
}
if ( V_21 > V_10 -> V_18 ) {
F_6 ( L_3 , V_5 ) ;
return - V_22 ;
}
F_12 ( V_10 -> V_13 , V_12 ) ;
F_7 () ;
F_14 ( V_21 , V_10 -> V_17 ) ;
F_7 () ;
F_15 ( V_10 -> V_13 , V_12 ) ;
return 0 ;
}
static T_1 void F_21 ( struct V_1 * V_23 )
{
T_2 V_14 , V_17 ;
struct V_7 * V_8 ;
struct V_9 * V_24 ;
const char * V_25 = V_23 -> V_26 ;
const char * V_27 ;
struct V_28 V_29 ;
int V_30 ;
int V_31 = 0 ;
if ( ! V_3 )
F_1 () ;
V_24 = F_22 ( sizeof( * V_24 ) , V_32 ) ;
if ( F_23 ( ! V_24 ) )
return;
V_24 -> V_13 = & V_33 ;
V_30 = F_24 ( V_23 , L_4 , & V_14 ) ;
if ( ! V_30 ) {
V_24 -> V_14 = V_3 + V_14 ;
V_30 = F_24 ( V_23 , L_5 , & V_24 -> V_15 ) ;
if ( V_30 ) {
F_6 ( L_6 ,
V_5 ) ;
return;
}
V_31 |= V_34 ;
}
V_30 = F_24 ( V_23 , L_7 , & V_17 ) ;
if ( ! V_30 ) {
V_24 -> V_17 = V_3 + V_17 ;
V_24 -> V_18 = 0x1f ;
F_24 ( V_23 , L_8 , & V_24 -> V_18 ) ;
V_31 |= V_35 ;
}
F_25 ( V_23 , L_9 , & V_25 ) ;
switch ( V_31 ) {
case V_34 :
V_29 . V_36 = & V_37 ;
break;
case V_35 :
V_29 . V_36 = & V_38 ;
break;
case V_39 :
V_29 . V_36 = & V_40 ;
break;
default:
F_6 ( L_10 ,
V_5 ) ;
F_26 ( V_24 ) ;
return;
}
V_29 . V_26 = V_25 ;
V_29 . V_12 = 0 ;
V_27 = F_27 ( V_23 , 0 ) ;
V_29 . V_41 = & V_27 ;
V_29 . V_42 = 1 ;
V_24 -> V_8 . V_29 = & V_29 ;
V_8 = & V_24 -> V_8 ;
V_30 = F_28 ( NULL , V_8 ) ;
if ( F_23 ( V_30 ) ) {
F_26 ( V_24 ) ;
return;
}
V_30 = F_29 ( V_23 , V_43 , V_8 ) ;
F_30 ( V_8 , V_25 , NULL ) ;
}
static int F_31 ( unsigned long V_19 , unsigned long V_16 ,
T_2 * V_44 , T_2 * V_45 )
{
unsigned long V_46 ;
if ( ( V_19 < V_16 * 4 ) || ( V_19 > V_16 * 62 ) ) {
F_6 ( L_11 , V_5 ) ;
* V_44 = 0 ;
* V_45 = 1 ;
return - V_22 ;
}
if ( V_19 <= V_16 * 31 )
* V_45 = 2 ;
else
* V_45 = 1 ;
* V_44 = V_19 / ( V_16 / * V_45 ) ;
V_46 = ( V_16 / * V_45 ) * * V_44 ;
if ( V_46 != V_19 )
F_32 ( L_12 , V_5 ,
V_19 , V_46 ) ;
return 0 ;
}
static int F_33 ( unsigned long V_19 ,
unsigned long V_16 , T_2 * V_44 , T_2 * V_47 ,
T_2 * V_48 )
{
unsigned long V_49 , V_50 , V_51 ;
if ( ! V_16 || ( V_19 < 37500000 ) || ( V_19 > 600000000 ) )
return - V_22 ;
* V_48 = V_19 <= 75000000 ? 3 : V_19 <= 150000000 ? 2 :
V_19 <= 300000000 ? 1 : 0 ;
V_50 = V_52 ;
for ( * V_47 = 5 ; * V_47 >= 3 ; ( * V_47 ) -- ) {
V_49 = V_19 * * V_47 * ( 1 << ( * V_48 ) ) ;
V_51 = V_49 % V_16 ;
if ( V_51 < V_50 ) {
* V_44 = V_49 / V_16 ;
if ( V_51 == 0 )
return 0 ;
V_50 = V_51 ;
}
}
if ( ( * V_44 < 3 ) || ( * V_44 > 1023 ) )
return - V_22 ;
F_32 ( L_13 , V_5 , V_50 ) ;
return 0 ;
}
static T_2 F_34 ( T_2 V_16 , T_2 V_47 )
{
T_2 V_53 = ( V_16 / 1000000 ) / ( V_47 + 1 ) ;
if ( ( V_53 < 10 ) || ( V_53 > 200 ) )
F_32 ( L_14 ,
V_5 , V_53 ) ;
if ( V_53 >= 166 )
return 7 ;
else if ( V_53 >= 104 )
return 6 ;
else if ( V_53 >= 65 )
return 5 ;
else if ( V_53 >= 42 )
return 4 ;
else if ( V_53 >= 26 )
return 3 ;
else if ( V_53 >= 16 )
return 2 ;
else if ( V_53 >= 10 )
return 1 ;
return 0 ;
}
static int F_35 ( unsigned long V_19 , unsigned long V_16 ,
T_2 * V_54 , T_2 * V_44 , T_2 * V_47 , T_2 * V_48 )
{
T_2 V_55 ;
int V_56 , V_57 ;
unsigned long V_46 , V_51 , V_58 ;
V_58 = ( unsigned long ) - 1 ;
for ( V_56 = 1 ; V_56 >= 0 ; V_56 -- )
for ( V_57 = 7 ; V_57 >= 0 ; V_57 -- )
for ( V_55 = 0 ; V_55 <= 255 ; V_55 ++ ) {
V_46 = V_16 * ( V_55 + 1 ) / ( ( V_56 + 1 ) * ( 1 << V_57 ) ) ;
if ( V_46 > V_19 )
continue;
V_51 = V_19 - V_46 ;
if ( V_51 == 0 ) {
* V_54 = F_34 ( V_16 , V_56 ) ;
* V_44 = V_55 ;
* V_47 = V_56 ;
* V_48 = V_57 ;
return 0 ;
}
if ( V_51 < V_58 ) {
V_58 = V_51 ;
* V_44 = V_55 ;
* V_47 = V_56 ;
* V_48 = V_57 ;
}
}
if ( V_58 == ( unsigned long ) - 1 ) {
F_32 ( L_15 , V_5 , V_19 ) ;
return - V_22 ;
}
F_32 ( L_12 , V_5 , V_19 ,
V_19 - V_58 ) ;
* V_54 = F_34 ( V_16 , * V_47 ) ;
return 0 ;
}
static int F_36 ( unsigned long V_19 , unsigned long V_16 ,
T_2 * V_44 , T_2 * V_47 , T_2 * V_48 )
{
T_2 V_55 ;
int V_56 , V_57 ;
unsigned long V_46 , V_51 , V_58 ;
V_58 = ( unsigned long ) - 1 ;
for ( V_56 = 1 ; V_56 >= 0 ; V_56 -- )
for ( V_57 = 3 ; V_57 >= 0 ; V_57 -- )
for ( V_55 = 0 ; V_55 <= 127 ; V_55 ++ ) {
V_46 = V_16 * ( ( V_55 + 1 ) * 2 ) /
( ( V_56 + 1 ) * ( 1 << V_57 ) ) ;
if ( V_46 > V_19 )
continue;
V_51 = V_19 - V_46 ;
if ( V_51 == 0 ) {
* V_44 = V_55 ;
* V_47 = V_56 ;
* V_48 = V_57 ;
return 0 ;
}
if ( V_51 < V_58 ) {
V_58 = V_51 ;
* V_44 = V_55 ;
* V_47 = V_56 ;
* V_48 = V_57 ;
}
}
if ( V_58 == ( unsigned long ) - 1 ) {
F_32 ( L_15 , V_5 , V_19 ) ;
return - V_22 ;
}
F_32 ( L_12 , V_5 , V_19 ,
V_19 - V_58 ) ;
return 0 ;
}
static int F_37 ( struct V_7 * V_8 , unsigned long V_19 ,
unsigned long V_16 )
{
struct V_59 * V_60 = F_38 ( V_8 ) ;
T_2 V_54 , V_55 , V_56 , V_57 ;
T_2 V_61 ;
unsigned long V_12 = 0 ;
int V_62 ;
switch ( V_60 -> type ) {
case V_63 :
V_62 = F_31 ( V_19 , V_16 , & V_55 , & V_56 ) ;
if ( ! V_62 )
V_61 = F_39 ( V_55 , V_56 ) ;
break;
case V_64 :
V_62 = F_33 ( V_19 , V_16 , & V_55 , & V_56 , & V_57 ) ;
if ( ! V_62 )
V_61 = F_40 ( V_55 , V_56 , V_57 ) ;
break;
case V_65 :
V_62 = F_35 ( V_19 , V_16 , & V_54 , & V_55 , & V_56 , & V_57 ) ;
if ( ! V_62 )
V_61 = F_41 ( V_54 , V_55 , V_56 , V_57 ) ;
break;
case V_66 :
V_62 = F_36 ( V_19 , V_16 , & V_55 , & V_56 , & V_57 ) ;
if ( ! V_62 )
V_61 = F_42 ( V_55 , V_56 , V_57 ) ;
break;
default:
F_6 ( L_16 , V_5 ) ;
V_62 = - V_22 ;
}
if ( V_62 )
return V_62 ;
F_12 ( V_60 -> V_13 , V_12 ) ;
F_7 () ;
F_14 ( V_61 , V_60 -> V_67 ) ;
F_7 () ;
F_15 ( V_60 -> V_13 , V_12 ) ;
return 0 ;
}
static long F_43 ( struct V_7 * V_8 , unsigned long V_19 ,
unsigned long * V_20 )
{
struct V_59 * V_60 = F_38 ( V_8 ) ;
T_2 V_54 , V_55 , V_56 , V_57 ;
long V_68 ;
int V_62 ;
switch ( V_60 -> type ) {
case V_63 :
V_62 = F_31 ( V_19 , * V_20 , & V_55 , & V_56 ) ;
if ( ! V_62 )
V_68 = F_44 ( * V_20 , V_55 , V_56 ) ;
break;
case V_64 :
V_62 = F_33 ( V_19 , * V_20 , & V_55 , & V_56 , & V_57 ) ;
if ( ! V_62 )
V_68 = F_45 ( * V_20 , V_55 , V_56 , V_57 ) ;
break;
case V_65 :
V_62 = F_35 ( V_19 , * V_20 , & V_54 , & V_55 , & V_56 , & V_57 ) ;
if ( ! V_62 )
V_68 = F_46 ( * V_20 , V_55 , V_56 , V_57 ) ;
break;
case V_66 :
V_62 = F_36 ( V_19 , * V_20 , & V_55 , & V_56 , & V_57 ) ;
if ( ! V_62 )
V_68 = F_47 ( * V_20 , V_55 , V_56 , V_57 ) ;
break;
default:
V_62 = - V_22 ;
}
if ( V_62 )
return V_62 ;
return V_68 ;
}
static unsigned long F_48 ( struct V_7 * V_8 ,
unsigned long V_16 )
{
struct V_59 * V_60 = F_38 ( V_8 ) ;
T_2 V_61 = F_8 ( V_60 -> V_67 ) ;
unsigned long V_69 ;
switch ( V_60 -> type ) {
case V_63 :
V_69 = V_16 * F_49 ( V_61 ) ;
V_69 /= F_50 ( V_61 ) ;
break;
case V_64 :
V_69 = V_16 * F_51 ( V_61 ) ;
V_69 /= F_52 ( V_61 ) ;
break;
case V_65 :
V_69 = V_16 * F_53 ( V_61 ) ;
V_69 /= F_54 ( V_61 ) ;
break;
case V_66 :
V_69 = V_16 * F_55 ( V_61 ) ;
V_69 /= F_56 ( V_61 ) ;
break;
default:
V_69 = 0 ;
}
return V_69 ;
}
static T_1 void F_57 ( struct V_1 * V_23 , int V_70 )
{
T_2 V_67 ;
struct V_7 * V_8 ;
struct V_59 * V_71 ;
const char * V_25 = V_23 -> V_26 ;
const char * V_27 ;
struct V_28 V_29 ;
int V_30 ;
if ( ! V_3 )
F_1 () ;
V_30 = F_24 ( V_23 , L_17 , & V_67 ) ;
if ( F_23 ( V_30 ) )
return;
V_71 = F_22 ( sizeof( * V_71 ) , V_32 ) ;
if ( F_23 ( ! V_71 ) )
return;
V_71 -> V_67 = V_3 + V_67 ;
V_71 -> V_13 = & V_33 ;
V_71 -> type = V_70 ;
F_25 ( V_23 , L_9 , & V_25 ) ;
V_29 . V_26 = V_25 ;
V_29 . V_36 = & V_72 ;
V_29 . V_12 = 0 ;
V_27 = F_27 ( V_23 , 0 ) ;
V_29 . V_41 = & V_27 ;
V_29 . V_42 = 1 ;
V_71 -> V_8 . V_29 = & V_29 ;
V_8 = & V_71 -> V_8 ;
V_30 = F_28 ( NULL , & V_71 -> V_8 ) ;
if ( F_23 ( V_30 ) ) {
F_26 ( V_71 ) ;
return;
}
V_30 = F_29 ( V_23 , V_43 , V_8 ) ;
F_30 ( V_8 , V_25 , NULL ) ;
}
static void T_1 F_58 ( struct V_1 * V_23 )
{
F_57 ( V_23 , V_63 ) ;
}
static void T_1 F_59 ( struct V_1 * V_23 )
{
F_57 ( V_23 , V_64 ) ;
}
static void T_1 F_60 ( struct V_1 * V_23 )
{
F_57 ( V_23 , V_65 ) ;
}
static void T_1 F_61 ( struct V_1 * V_23 )
{
F_57 ( V_23 , V_66 ) ;
}
