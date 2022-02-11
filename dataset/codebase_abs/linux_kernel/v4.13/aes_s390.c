static int F_1 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 ;
V_6 -> V_8 . V_9 -> V_10 . V_11 &= ~ V_12 ;
V_6 -> V_8 . V_9 -> V_10 . V_11 |= ( V_2 -> V_11 &
V_12 ) ;
V_7 = F_3 ( V_6 -> V_8 . V_9 , V_3 , V_4 ) ;
if ( V_7 ) {
V_2 -> V_11 &= ~ V_13 ;
V_2 -> V_11 |= ( V_6 -> V_8 . V_9 -> V_10 . V_11 &
V_13 ) ;
}
return V_7 ;
}
static int F_4 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_14 ;
V_14 = ( V_4 == 16 ) ? V_15 :
( V_4 == 24 ) ? V_16 :
( V_4 == 32 ) ? V_17 : 0 ;
V_6 -> V_14 = ( V_14 && F_5 ( & V_18 , V_14 ) ) ? V_14 : 0 ;
if ( ! V_6 -> V_14 )
return F_1 ( V_2 , V_3 , V_4 ) ;
V_6 -> V_4 = V_4 ;
memcpy ( V_6 -> V_19 , V_3 , V_4 ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 , T_1 * V_20 , const T_1 * V_21 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_7 ( ! V_6 -> V_14 ) ) {
F_8 ( V_6 -> V_8 . V_9 , V_20 , V_21 ) ;
return;
}
F_9 ( V_6 -> V_14 , & V_6 -> V_19 , V_20 , V_21 , V_22 ) ;
}
static void F_10 ( struct V_1 * V_2 , T_1 * V_20 , const T_1 * V_21 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_7 ( ! V_6 -> V_14 ) ) {
F_11 ( V_6 -> V_8 . V_9 , V_20 , V_21 ) ;
return;
}
F_9 ( V_6 -> V_14 | V_23 ,
& V_6 -> V_19 , V_20 , V_21 , V_22 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
const char * V_24 = V_2 -> V_25 -> V_26 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_8 . V_9 = F_13 ( V_24 , 0 ,
V_27 | V_28 ) ;
if ( F_14 ( V_6 -> V_8 . V_9 ) ) {
F_15 ( L_1 ,
V_24 ) ;
return F_16 ( V_6 -> V_8 . V_9 ) ;
}
return 0 ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_18 ( V_6 -> V_8 . V_9 ) ;
V_6 -> V_8 . V_9 = NULL ;
}
static int F_19 ( struct V_1 * V_2 , const T_1 * V_19 ,
unsigned int V_29 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_7 ;
F_20 ( V_6 -> V_8 . V_30 , V_12 ) ;
F_21 ( V_6 -> V_8 . V_30 , V_2 -> V_11 &
V_12 ) ;
V_7 = F_22 ( V_6 -> V_8 . V_30 , V_19 , V_29 ) ;
V_2 -> V_11 &= ~ V_13 ;
V_2 -> V_11 |= F_23 ( V_6 -> V_8 . V_30 ) &
V_13 ;
return V_7 ;
}
static int F_24 ( struct V_31 * V_32 ,
struct V_33 * V_34 , struct V_33 * V_35 ,
unsigned int V_36 )
{
unsigned int V_7 ;
struct V_37 * V_2 = V_32 -> V_2 ;
struct V_5 * V_6 = F_25 ( V_2 ) ;
F_26 ( V_38 , V_6 -> V_8 . V_30 ) ;
F_27 ( V_38 , V_6 -> V_8 . V_30 ) ;
F_28 ( V_38 , V_32 -> V_39 , NULL , NULL ) ;
F_29 ( V_38 , V_35 , V_34 , V_36 , V_32 -> V_40 ) ;
V_7 = F_30 ( V_38 ) ;
F_31 ( V_38 ) ;
return V_7 ;
}
static int F_32 ( struct V_31 * V_32 ,
struct V_33 * V_34 , struct V_33 * V_35 ,
unsigned int V_36 )
{
unsigned int V_7 ;
struct V_37 * V_2 = V_32 -> V_2 ;
struct V_5 * V_6 = F_25 ( V_2 ) ;
F_26 ( V_38 , V_6 -> V_8 . V_30 ) ;
F_27 ( V_38 , V_6 -> V_8 . V_30 ) ;
F_28 ( V_38 , V_32 -> V_39 , NULL , NULL ) ;
F_29 ( V_38 , V_35 , V_34 , V_36 , V_32 -> V_40 ) ;
V_7 = F_33 ( V_38 ) ;
return V_7 ;
}
static int F_34 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_14 ;
V_14 = ( V_4 == 16 ) ? V_15 :
( V_4 == 24 ) ? V_16 :
( V_4 == 32 ) ? V_17 : 0 ;
V_6 -> V_14 = ( V_14 && F_5 ( & V_18 , V_14 ) ) ? V_14 : 0 ;
if ( ! V_6 -> V_14 )
return F_19 ( V_2 , V_3 , V_4 ) ;
V_6 -> V_4 = V_4 ;
memcpy ( V_6 -> V_19 , V_3 , V_4 ) ;
return 0 ;
}
static int F_35 ( struct V_31 * V_32 , unsigned long V_41 ,
struct V_42 * V_43 )
{
struct V_5 * V_6 = F_25 ( V_32 -> V_2 ) ;
unsigned int V_36 , V_44 ;
int V_7 ;
V_7 = F_36 ( V_32 , V_43 ) ;
while ( ( V_36 = V_43 -> V_36 ) >= V_22 ) {
V_44 = V_36 & ~ ( V_22 - 1 ) ;
F_9 ( V_6 -> V_14 | V_41 , V_6 -> V_19 ,
V_43 -> V_34 . V_45 . V_46 , V_43 -> V_35 . V_45 . V_46 , V_44 ) ;
V_7 = F_37 ( V_32 , V_43 , V_36 - V_44 ) ;
}
return V_7 ;
}
static int F_38 ( struct V_31 * V_32 ,
struct V_33 * V_34 , struct V_33 * V_35 ,
unsigned int V_36 )
{
struct V_5 * V_6 = F_25 ( V_32 -> V_2 ) ;
struct V_42 V_43 ;
if ( F_7 ( ! V_6 -> V_14 ) )
return F_32 ( V_32 , V_34 , V_35 , V_36 ) ;
F_39 ( & V_43 , V_34 , V_35 , V_36 ) ;
return F_35 ( V_32 , 0 , & V_43 ) ;
}
static int F_40 ( struct V_31 * V_32 ,
struct V_33 * V_34 , struct V_33 * V_35 ,
unsigned int V_36 )
{
struct V_5 * V_6 = F_25 ( V_32 -> V_2 ) ;
struct V_42 V_43 ;
if ( F_7 ( ! V_6 -> V_14 ) )
return F_24 ( V_32 , V_34 , V_35 , V_36 ) ;
F_39 ( & V_43 , V_34 , V_35 , V_36 ) ;
return F_35 ( V_32 , V_23 , & V_43 ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
const char * V_24 = V_2 -> V_25 -> V_26 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_8 . V_30 = F_42 ( V_24 , 0 ,
V_27 |
V_28 ) ;
if ( F_14 ( V_6 -> V_8 . V_30 ) ) {
F_15 ( L_1 ,
V_24 ) ;
return F_16 ( V_6 -> V_8 . V_30 ) ;
}
return 0 ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_44 ( V_6 -> V_8 . V_30 ) ;
}
static int F_45 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_14 ;
V_14 = ( V_4 == 16 ) ? V_47 :
( V_4 == 24 ) ? V_48 :
( V_4 == 32 ) ? V_49 : 0 ;
V_6 -> V_14 = ( V_14 && F_5 ( & V_50 , V_14 ) ) ? V_14 : 0 ;
if ( ! V_6 -> V_14 )
return F_19 ( V_2 , V_3 , V_4 ) ;
V_6 -> V_4 = V_4 ;
memcpy ( V_6 -> V_19 , V_3 , V_4 ) ;
return 0 ;
}
static int F_46 ( struct V_31 * V_32 , unsigned long V_41 ,
struct V_42 * V_43 )
{
struct V_5 * V_6 = F_25 ( V_32 -> V_2 ) ;
unsigned int V_36 , V_44 ;
int V_7 ;
struct {
T_1 V_51 [ V_22 ] ;
T_1 V_19 [ V_52 ] ;
} V_53 ;
V_7 = F_36 ( V_32 , V_43 ) ;
memcpy ( V_53 . V_51 , V_43 -> V_51 , V_22 ) ;
memcpy ( V_53 . V_19 , V_6 -> V_19 , V_6 -> V_4 ) ;
while ( ( V_36 = V_43 -> V_36 ) >= V_22 ) {
V_44 = V_36 & ~ ( V_22 - 1 ) ;
F_47 ( V_6 -> V_14 | V_41 , & V_53 ,
V_43 -> V_34 . V_45 . V_46 , V_43 -> V_35 . V_45 . V_46 , V_44 ) ;
V_7 = F_37 ( V_32 , V_43 , V_36 - V_44 ) ;
}
memcpy ( V_43 -> V_51 , V_53 . V_51 , V_22 ) ;
return V_7 ;
}
static int F_48 ( struct V_31 * V_32 ,
struct V_33 * V_34 , struct V_33 * V_35 ,
unsigned int V_36 )
{
struct V_5 * V_6 = F_25 ( V_32 -> V_2 ) ;
struct V_42 V_43 ;
if ( F_7 ( ! V_6 -> V_14 ) )
return F_32 ( V_32 , V_34 , V_35 , V_36 ) ;
F_39 ( & V_43 , V_34 , V_35 , V_36 ) ;
return F_46 ( V_32 , 0 , & V_43 ) ;
}
static int F_49 ( struct V_31 * V_32 ,
struct V_33 * V_34 , struct V_33 * V_35 ,
unsigned int V_36 )
{
struct V_5 * V_6 = F_25 ( V_32 -> V_2 ) ;
struct V_42 V_43 ;
if ( F_7 ( ! V_6 -> V_14 ) )
return F_24 ( V_32 , V_34 , V_35 , V_36 ) ;
F_39 ( & V_43 , V_34 , V_35 , V_36 ) ;
return F_46 ( V_32 , V_23 , & V_43 ) ;
}
static int F_50 ( struct V_1 * V_2 , const T_1 * V_19 ,
unsigned int V_29 )
{
struct V_54 * V_55 = F_2 ( V_2 ) ;
unsigned int V_7 ;
F_20 ( V_55 -> V_8 , V_12 ) ;
F_21 ( V_55 -> V_8 , V_2 -> V_11 &
V_12 ) ;
V_7 = F_22 ( V_55 -> V_8 , V_19 , V_29 ) ;
V_2 -> V_11 &= ~ V_13 ;
V_2 -> V_11 |= F_23 ( V_55 -> V_8 ) &
V_13 ;
return V_7 ;
}
static int F_51 ( struct V_31 * V_32 ,
struct V_33 * V_34 , struct V_33 * V_35 ,
unsigned int V_36 )
{
struct V_37 * V_2 = V_32 -> V_2 ;
struct V_54 * V_55 = F_25 ( V_2 ) ;
F_26 ( V_38 , V_55 -> V_8 ) ;
unsigned int V_7 ;
F_27 ( V_38 , V_55 -> V_8 ) ;
F_28 ( V_38 , V_32 -> V_39 , NULL , NULL ) ;
F_29 ( V_38 , V_35 , V_34 , V_36 , V_32 -> V_40 ) ;
V_7 = F_30 ( V_38 ) ;
F_31 ( V_38 ) ;
return V_7 ;
}
static int F_52 ( struct V_31 * V_32 ,
struct V_33 * V_34 , struct V_33 * V_35 ,
unsigned int V_36 )
{
struct V_37 * V_2 = V_32 -> V_2 ;
struct V_54 * V_55 = F_25 ( V_2 ) ;
F_26 ( V_38 , V_55 -> V_8 ) ;
unsigned int V_7 ;
F_27 ( V_38 , V_55 -> V_8 ) ;
F_28 ( V_38 , V_32 -> V_39 , NULL , NULL ) ;
F_29 ( V_38 , V_35 , V_34 , V_36 , V_32 -> V_40 ) ;
V_7 = F_33 ( V_38 ) ;
F_31 ( V_38 ) ;
return V_7 ;
}
static int F_53 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_54 * V_55 = F_2 ( V_2 ) ;
unsigned long V_14 ;
int V_56 ;
V_56 = F_54 ( V_2 , V_3 , V_4 ) ;
if ( V_56 )
return V_56 ;
if ( V_57 && V_4 != 32 && V_4 != 64 ) {
V_2 -> V_11 |= V_58 ;
return - V_59 ;
}
V_14 = ( V_4 == 32 ) ? V_60 :
( V_4 == 64 ) ? V_61 : 0 ;
V_55 -> V_14 = ( V_14 && F_5 ( & V_18 , V_14 ) ) ? V_14 : 0 ;
if ( ! V_55 -> V_14 )
return F_50 ( V_2 , V_3 , V_4 ) ;
V_4 = V_4 / 2 ;
V_55 -> V_4 = V_4 ;
memcpy ( V_55 -> V_19 , V_3 , V_4 ) ;
memcpy ( V_55 -> V_62 , V_3 + V_4 , V_4 ) ;
return 0 ;
}
static int F_55 ( struct V_31 * V_32 , unsigned long V_41 ,
struct V_42 * V_43 )
{
struct V_54 * V_55 = F_25 ( V_32 -> V_2 ) ;
unsigned int V_63 , V_36 , V_44 ;
int V_7 ;
struct {
T_1 V_19 [ 32 ] ;
T_1 V_64 [ 16 ] ;
T_1 V_65 [ 16 ] ;
T_1 V_66 [ 16 ] ;
T_1 V_67 [ 16 ] ;
} V_68 ;
struct {
T_1 V_19 [ 32 ] ;
T_1 V_69 [ 16 ] ;
} V_70 ;
V_7 = F_36 ( V_32 , V_43 ) ;
V_63 = V_55 -> V_4 & 0x10 ;
memset ( V_68 . V_65 , 0 , sizeof( V_68 . V_65 ) ) ;
memset ( V_68 . V_66 , 0 , sizeof( V_68 . V_66 ) ) ;
memset ( V_68 . V_67 , 0 , sizeof( V_68 . V_67 ) ) ;
memcpy ( V_68 . V_64 , V_43 -> V_51 , sizeof( V_68 . V_64 ) ) ;
memcpy ( V_68 . V_19 + V_63 , V_55 -> V_62 , V_55 -> V_4 ) ;
F_56 ( V_55 -> V_14 , V_68 . V_19 + V_63 ) ;
memcpy ( V_70 . V_19 + V_63 , V_55 -> V_19 , V_55 -> V_4 ) ;
memcpy ( V_70 . V_69 , V_68 . V_67 , 16 ) ;
while ( ( V_36 = V_43 -> V_36 ) >= V_22 ) {
V_44 = V_36 & ~ ( V_22 - 1 ) ;
F_9 ( V_55 -> V_14 | V_41 , V_70 . V_19 + V_63 ,
V_43 -> V_34 . V_45 . V_46 , V_43 -> V_35 . V_45 . V_46 , V_44 ) ;
V_7 = F_37 ( V_32 , V_43 , V_36 - V_44 ) ;
}
return V_7 ;
}
static int F_57 ( struct V_31 * V_32 ,
struct V_33 * V_34 , struct V_33 * V_35 ,
unsigned int V_36 )
{
struct V_54 * V_55 = F_25 ( V_32 -> V_2 ) ;
struct V_42 V_43 ;
if ( F_7 ( ! V_55 -> V_14 ) )
return F_52 ( V_32 , V_34 , V_35 , V_36 ) ;
F_39 ( & V_43 , V_34 , V_35 , V_36 ) ;
return F_55 ( V_32 , 0 , & V_43 ) ;
}
static int F_58 ( struct V_31 * V_32 ,
struct V_33 * V_34 , struct V_33 * V_35 ,
unsigned int V_36 )
{
struct V_54 * V_55 = F_25 ( V_32 -> V_2 ) ;
struct V_42 V_43 ;
if ( F_7 ( ! V_55 -> V_14 ) )
return F_51 ( V_32 , V_34 , V_35 , V_36 ) ;
F_39 ( & V_43 , V_34 , V_35 , V_36 ) ;
return F_55 ( V_32 , V_23 , & V_43 ) ;
}
static int F_59 ( struct V_1 * V_2 )
{
const char * V_24 = V_2 -> V_25 -> V_26 ;
struct V_54 * V_55 = F_2 ( V_2 ) ;
V_55 -> V_8 = F_42 ( V_24 , 0 ,
V_27 |
V_28 ) ;
if ( F_14 ( V_55 -> V_8 ) ) {
F_15 ( L_2 ,
V_24 ) ;
return F_16 ( V_55 -> V_8 ) ;
}
return 0 ;
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = F_2 ( V_2 ) ;
F_44 ( V_55 -> V_8 ) ;
}
static int F_61 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_14 ;
V_14 = ( V_4 == 16 ) ? V_71 :
( V_4 == 24 ) ? V_72 :
( V_4 == 32 ) ? V_73 : 0 ;
V_6 -> V_14 = ( V_14 && F_5 ( & V_74 , V_14 ) ) ? V_14 : 0 ;
if ( ! V_6 -> V_14 )
return F_19 ( V_2 , V_3 , V_4 ) ;
V_6 -> V_4 = V_4 ;
memcpy ( V_6 -> V_19 , V_3 , V_4 ) ;
return 0 ;
}
static unsigned int F_62 ( T_1 * V_75 , T_1 * V_51 , unsigned int V_36 )
{
unsigned int V_76 , V_44 ;
memcpy ( V_75 , V_51 , V_22 ) ;
V_44 = ( V_36 > V_77 ) ? V_77 : V_36 & ~ ( V_22 - 1 ) ;
for ( V_76 = ( V_44 / V_22 ) - 1 ; V_76 > 0 ; V_76 -- ) {
memcpy ( V_75 + V_22 , V_75 , V_22 ) ;
F_63 ( V_75 + V_22 , V_22 ) ;
V_75 += V_22 ;
}
return V_44 ;
}
static int F_64 ( struct V_31 * V_32 , unsigned long V_41 ,
struct V_42 * V_43 )
{
struct V_5 * V_6 = F_25 ( V_32 -> V_2 ) ;
T_1 V_78 [ V_22 ] , * V_75 ;
unsigned int V_44 , V_36 ;
int V_7 , V_79 ;
V_79 = F_65 ( & V_80 ) ;
V_7 = F_66 ( V_32 , V_43 , V_22 ) ;
while ( ( V_36 = V_43 -> V_36 ) >= V_22 ) {
V_44 = V_22 ;
if ( V_36 >= 2 * V_22 && V_79 )
V_44 = F_62 ( V_81 , V_43 -> V_51 , V_36 ) ;
V_75 = ( V_44 > V_22 ) ? V_81 : V_43 -> V_51 ;
F_67 ( V_6 -> V_14 | V_41 , V_6 -> V_19 ,
V_43 -> V_34 . V_45 . V_46 , V_43 -> V_35 . V_45 . V_46 ,
V_44 , V_75 ) ;
if ( V_75 == V_81 )
memcpy ( V_43 -> V_51 , V_75 + V_44 - V_22 ,
V_22 ) ;
F_63 ( V_43 -> V_51 , V_22 ) ;
V_7 = F_37 ( V_32 , V_43 , V_36 - V_44 ) ;
}
if ( V_79 )
F_68 ( & V_80 ) ;
if ( V_36 ) {
F_67 ( V_6 -> V_14 | V_41 , V_6 -> V_19 ,
V_78 , V_43 -> V_35 . V_45 . V_46 ,
V_22 , V_43 -> V_51 ) ;
memcpy ( V_43 -> V_34 . V_45 . V_46 , V_78 , V_36 ) ;
F_63 ( V_43 -> V_51 , V_22 ) ;
V_7 = F_37 ( V_32 , V_43 , 0 ) ;
}
return V_7 ;
}
static int F_69 ( struct V_31 * V_32 ,
struct V_33 * V_34 , struct V_33 * V_35 ,
unsigned int V_36 )
{
struct V_5 * V_6 = F_25 ( V_32 -> V_2 ) ;
struct V_42 V_43 ;
if ( F_7 ( ! V_6 -> V_14 ) )
return F_32 ( V_32 , V_34 , V_35 , V_36 ) ;
F_39 ( & V_43 , V_34 , V_35 , V_36 ) ;
return F_64 ( V_32 , 0 , & V_43 ) ;
}
static int F_70 ( struct V_31 * V_32 ,
struct V_33 * V_34 , struct V_33 * V_35 ,
unsigned int V_36 )
{
struct V_5 * V_6 = F_25 ( V_32 -> V_2 ) ;
struct V_42 V_43 ;
if ( F_7 ( ! V_6 -> V_14 ) )
return F_24 ( V_32 , V_34 , V_35 , V_36 ) ;
F_39 ( & V_43 , V_34 , V_35 , V_36 ) ;
return F_64 ( V_32 , V_23 , & V_43 ) ;
}
static int F_71 ( struct V_82 * V_83 )
{
int V_7 ;
V_7 = F_72 ( V_83 ) ;
if ( ! V_7 )
V_84 [ V_85 ++ ] = V_83 ;
return V_7 ;
}
static void F_73 ( void )
{
while ( V_85 -- )
F_74 ( V_84 [ V_85 ] ) ;
if ( V_81 )
F_75 ( ( unsigned long ) V_81 ) ;
}
static int T_2 F_76 ( void )
{
int V_7 ;
F_77 ( V_86 , & V_18 ) ;
F_77 ( V_87 , & V_50 ) ;
F_77 ( V_88 , & V_74 ) ;
if ( F_5 ( & V_18 , V_15 ) ||
F_5 ( & V_18 , V_16 ) ||
F_5 ( & V_18 , V_17 ) ) {
V_7 = F_71 ( & V_89 ) ;
if ( V_7 )
goto V_90;
V_7 = F_71 ( & V_91 ) ;
if ( V_7 )
goto V_90;
}
if ( F_5 ( & V_50 , V_47 ) ||
F_5 ( & V_50 , V_48 ) ||
F_5 ( & V_50 , V_49 ) ) {
V_7 = F_71 ( & V_92 ) ;
if ( V_7 )
goto V_90;
}
if ( F_5 ( & V_18 , V_60 ) ||
F_5 ( & V_18 , V_61 ) ) {
V_7 = F_71 ( & V_93 ) ;
if ( V_7 )
goto V_90;
}
if ( F_5 ( & V_74 , V_71 ) ||
F_5 ( & V_74 , V_72 ) ||
F_5 ( & V_74 , V_73 ) ) {
V_81 = ( T_1 * ) F_78 ( V_94 ) ;
if ( ! V_81 ) {
V_7 = - V_95 ;
goto V_90;
}
V_7 = F_71 ( & V_96 ) ;
if ( V_7 )
goto V_90;
}
return 0 ;
V_90:
F_73 () ;
return V_7 ;
}
