static inline T_1 F_1 ( struct V_1 * V_2 ,
T_2 V_3 )
{
return F_2 ( V_2 -> V_4 , V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 ,
T_2 V_3 ,
T_1 V_5 )
{
F_4 ( V_2 -> V_4 , V_3 , V_5 ) ;
}
static inline T_1 F_5 ( struct V_6 * V_4 )
{
T_1 V_7 = F_2 ( V_4 , V_8 ) ;
if ( V_7 )
return F_2 ( V_4 , V_8 ) & V_9 ;
else
return 0x3f ;
}
static struct V_6 * F_6 ( struct V_6 * V_10 , int V_11 )
{
struct V_12 * V_13 = V_10 -> V_13 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_13 -> V_15 ; V_14 ++ ) {
struct V_6 * V_4 ;
V_4 = & ( V_13 -> V_16 [ V_14 ] ) ;
if ( F_5 ( V_4 ) == V_11 )
return V_4 ;
}
return NULL ;
}
unsigned int F_7 ( struct V_6 * V_4 )
{
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_6 * V_17 = V_13 -> V_18 . V_4 ;
T_1 V_11 ;
T_1 V_19 ;
T_1 V_20 ;
unsigned int V_21 ;
V_11 = F_5 ( V_4 ) ;
if ( V_11 == 0x3f )
return 6 ;
V_19 = F_2 ( V_13 -> V_18 . V_4 , V_22 ) ;
for ( V_21 = 1 ; V_21 <= 4 ; V_21 ++ ) {
V_20 = ( ( V_19 & V_23 [ V_21 ] ) >> V_24 [ V_21 ] ) ;
if ( V_20 == V_11 )
break;
}
if ( V_21 == 5 ) {
if ( ( 1 << V_11 ) & F_2 ( V_17 , V_25 ) )
V_21 = 0 ;
}
return V_21 ;
}
static void F_8 ( struct V_12 * V_13 , unsigned int V_21 )
{
struct V_6 * V_4 = V_13 -> V_18 . V_4 ;
if ( V_21 == 0 ) {
F_4 ( V_4 , V_25 , 0 ) ;
} else {
F_4 ( V_4 , V_22 ,
F_2 ( V_4 , V_22 ) |
V_23 [ V_21 ] ) ;
}
}
static void F_9 ( struct V_6 * V_4 , unsigned int V_21 )
{
unsigned int V_26 = F_7 ( V_4 ) ;
struct V_12 * V_13 = V_4 -> V_13 ;
struct V_6 * V_17 = V_13 -> V_18 . V_4 ;
T_1 V_11 = F_5 ( V_4 ) ;
F_10 ( V_26 == 6 ) ;
V_4 -> V_21 = V_21 + 2 ;
if ( V_26 == 0 )
F_4 ( V_17 , V_25 , ( ~ ( 1 << V_11 ) & F_2 ( V_17 , V_25 ) ) ) ;
else if ( V_26 != 5 )
F_8 ( V_13 , V_26 ) ;
if ( V_21 == 0 ) {
F_4 ( V_17 , V_25 , ( ( 1 << V_11 ) | F_2 ( V_17 , V_25 ) ) ) ;
} else {
T_1 V_19 = F_2 ( V_17 , V_22 ) ;
if ( ( V_19 & V_23 [ V_21 ] ) != V_23 [ V_21 ] ) {
T_1 V_27 = ( V_19 & V_23 [ V_21 ] ) >> V_24 [ V_21 ] ;
struct V_6 * V_28 = F_6 ( V_4 , V_27 ) ;
if ( V_28 )
F_9 ( V_28 , 0 ) ;
}
V_11 <<= V_24 [ V_21 ] ;
V_11 |= ( V_19 & ~ V_23 [ V_21 ] ) ;
F_4 ( V_17 , V_22 , V_11 ) ;
}
F_11 ( L_1 ,
V_4 -> V_29 . V_30 , V_26 + 2 , V_21 + 2 ) ;
}
static void F_12 ( struct V_6 * V_4 , unsigned int V_21 )
{
static const char * V_31 [] = { L_2 , L_3 , L_4 , L_5 , L_6 , L_7 , L_8 } ;
F_11 ( L_9 ,
V_4 -> V_29 . V_30 ,
V_31 [ 0 ] , V_21 == 0 ? L_10 : L_11 ,
V_31 [ 1 ] , V_21 == 1 ? L_10 : L_11 ,
V_31 [ 2 ] , V_21 == 2 ? L_10 : L_11 ,
V_31 [ 3 ] , V_21 == 3 ? L_10 : L_11 ,
V_31 [ 4 ] , V_21 == 4 ? L_10 : L_11 ,
V_31 [ 5 ] , V_21 == 5 ? L_10 : L_11 ,
V_31 [ 6 ] , V_21 == 6 ? L_10 : L_11 ) ;
}
static void F_13 ( struct V_12 * V_13 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_13 -> V_15 ; V_14 ++ ) {
struct V_6 * V_4 ;
V_4 = & ( V_13 -> V_16 [ V_14 ] ) ;
F_12 ( V_4 , F_7 ( V_4 ) ) ;
}
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_4 -> V_13 ;
if ( F_15 ( & V_13 -> V_32 ) )
V_2 -> V_33 = F_16 ( & V_13 -> V_32 , V_2 -> V_34 ) ;
else if ( F_17 ( & V_13 -> V_35 ) )
V_2 -> V_33 = F_18 ( & V_13 -> V_35 , V_2 -> V_34 ) ;
else
V_2 -> V_33 = 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_4 -> V_13 ;
struct V_36 * V_37 = & V_2 -> V_37 ;
struct V_38 * V_39 = & V_2 -> V_39 ;
if ( ! F_17 ( & V_13 -> V_35 ) ) {
V_39 -> V_40 = true ;
V_39 -> V_41 = 2 ;
V_39 -> V_42 = V_43 ;
V_39 -> V_44 = V_45 ;
goto V_38;
}
switch ( V_13 -> V_35 . V_46 & V_47 ) {
case V_48 :
case V_49 :
F_20 ( L_12 ) ;
F_21 ( & V_13 -> V_35 ) ;
break;
case V_50 :
F_20 ( L_13 ) ;
V_39 -> V_40 = true ;
V_39 -> V_42 = V_51 ;
V_39 -> V_44 = V_52 ;
if ( ( F_2 ( V_13 -> V_35 . V_4 , V_53 )
& V_54 ) == 0 )
V_39 -> V_41 = 1 ;
else
V_39 -> V_41 = 2 ;
break;
}
V_38:
if ( V_37 -> V_40 ) {
#ifdef F_22
F_23 ( V_37 -> V_42 , V_37 -> V_55 ) ;
#endif
} else if ( V_39 -> V_40 ) {
#ifdef F_22
F_23 ( V_39 -> V_42 , V_39 -> V_44 ) ;
#endif
V_56 . V_57 = V_39 -> V_41 ;
V_58 . V_59 = V_39 -> V_42 ;
V_58 . V_60 = V_39 -> V_42 + V_39 -> V_44 ;
}
}
T_1 F_24 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_4 -> V_13 ;
T_1 V_61 , V_62 , V_63 , V_64 = 0 ;
if ( V_13 -> V_35 . V_46 & V_65 )
return F_25 ( & V_13 -> V_35 ) ;
if ( F_15 ( & V_13 -> V_32 ) ) {
F_26 ( & V_13 -> V_32 , & V_61 , & V_62 , & V_63 ) ;
} else if ( F_17 ( & V_13 -> V_35 ) ) {
F_27 ( & V_13 -> V_35 , & V_61 , & V_62 , & V_63 ) ;
} else
return 0 ;
if ( ( V_61 == V_66 ) || ( V_13 -> V_67 == 0x5365 ) ) {
V_64 = 200000000 ;
} else {
V_64 = F_28 ( V_61 , V_62 , V_63 ) ;
}
if ( V_61 == V_68 ) {
V_64 *= 2 ;
}
return V_64 ;
}
void F_29 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
struct V_6 * V_4 ;
unsigned long V_69 , V_70 ;
unsigned int V_21 , V_14 ;
if ( ! V_2 -> V_4 )
return;
F_11 ( L_14 ) ;
V_13 = V_2 -> V_4 -> V_13 ;
V_69 = F_30 ( V_13 ) ;
if ( ! V_69 )
V_69 = 100000000 ;
V_70 = 1000000000 / V_69 ;
if ( F_15 ( & V_13 -> V_32 ) )
F_31 ( & V_13 -> V_32 , V_70 ) ;
else if ( F_17 ( & V_13 -> V_35 ) )
F_32 ( & V_13 -> V_35 , V_70 ) ;
for ( V_21 = 2 , V_14 = 0 ; V_14 < V_13 -> V_15 ; V_14 ++ ) {
int V_71 ;
V_4 = & ( V_13 -> V_16 [ V_14 ] ) ;
V_71 = F_7 ( V_4 ) ;
if ( V_71 > 4 )
V_4 -> V_21 = 0 ;
else
V_4 -> V_21 = V_71 + 2 ;
if ( V_4 -> V_21 > 5 )
continue;
switch ( V_4 -> V_29 . V_30 ) {
case V_72 :
if ( ( V_13 -> V_67 == 0x4710 ) && ( V_21 <= 4 ) ) {
F_9 ( V_4 , V_21 ++ ) ;
}
break;
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
if ( V_21 <= 4 ) {
F_9 ( V_4 , V_21 ++ ) ;
break;
}
case V_78 :
F_9 ( V_4 , 0 ) ;
break;
}
}
F_11 ( L_15 ) ;
F_13 ( V_13 ) ;
F_14 ( V_2 ) ;
F_19 ( V_2 ) ;
}
