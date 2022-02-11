static void F_1 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
F_2 ( V_3 ) ;
}
static int F_3 ( struct V_2 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_4 -> V_9 ;
unsigned int V_10 = F_4 ( V_6 ) ;
struct V_11 * V_12 ;
V_12 = F_5 ( V_8 -> V_13 , V_4 ) ;
if ( V_12 -> V_14 )
V_10 = V_10 / F_6 ( V_6 ) * 8 ;
return F_7 ( V_4 , V_10 ) ;
}
static int F_8 ( struct V_2 * V_4 )
{
F_9 ( V_4 ) ;
return 0 ;
}
static int F_10 ( struct V_2 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_9 ;
int V_19 = F_11 ( V_16 , V_16 -> V_20 ) ;
struct V_11 * V_12 ;
V_12 = F_5 ( V_8 -> V_13 , V_4 ) ;
if ( V_12 -> V_14 )
V_19 = V_19 / V_16 -> V_21 * 8 ;
F_12 ( L_1 , V_22 ) ;
if ( V_4 -> V_23 == V_24 ) {
F_13 ( V_18 , F_1 , V_4 ) ;
F_14 ( V_18 , V_16 -> V_25 ,
V_16 -> V_26 , V_19 ) ;
} else {
F_15 ( V_18 , F_1 , V_4 ) ;
F_16 ( V_18 , V_16 -> V_25 ,
V_16 -> V_26 , V_19 ) ;
}
return 0 ;
}
static int F_17 ( struct V_2 * V_4 , int V_27 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_9 ;
int V_28 = 0 ;
F_12 ( L_1 , V_22 ) ;
switch ( V_27 ) {
case V_29 :
if ( V_4 -> V_23 == V_24 )
F_18 ( V_18 ) ;
else
F_19 ( V_18 ) ;
break;
case V_30 :
case V_31 :
case V_32 :
if ( V_4 -> V_23 == V_24 )
F_20 ( V_18 ) ;
else
F_21 ( V_18 ) ;
break;
default:
V_28 = - V_33 ;
}
return V_28 ;
}
static T_1 F_22 ( struct V_2 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_9 ;
unsigned int V_34 ;
T_1 V_35 ;
struct V_11 * V_12 ;
V_12 = F_5 ( V_8 -> V_13 , V_4 ) ;
F_12 ( L_1 , V_22 ) ;
if ( V_4 -> V_23 == V_24 ) {
V_34 = F_23 ( V_18 ) ;
} else {
V_34 = F_24 ( V_18 ) ;
}
if ( V_34 == F_25 ( V_4 ) )
V_34 = 0 ;
V_35 = F_26 ( V_4 -> V_16 , V_34 ) ;
if ( V_12 -> V_14 )
V_35 = V_35 * V_16 -> V_21 / 8 ;
return V_35 ;
}
static int F_27 ( struct V_2 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_36 * V_13 = V_8 -> V_13 ;
struct V_17 * V_37 = F_28 ( V_13 ) ;
struct V_15 * V_16 = V_4 -> V_16 ;
struct V_38 * V_39 = & V_4 -> V_40 ;
struct V_11 * V_12 ;
int V_28 ;
V_12 = F_5 ( V_8 -> V_13 , V_4 ) ;
F_12 ( L_1 , V_22 ) ;
F_29 ( V_4 , & V_41 ) ;
if ( V_12 -> V_14 )
V_16 -> V_42 . V_43 /= 4 ;
else
V_16 -> V_42 . V_44 |= V_45 ;
V_28 = F_30 ( V_16 ,
V_46 ) ;
if ( V_28 < 0 )
goto V_47;
if ( V_37 != NULL ) {
if ( V_4 -> V_23 == V_24 )
V_37 -> V_48 = V_39 -> V_49 ;
else
V_37 -> V_50 = V_39 -> V_49 ;
V_16 -> V_9 = V_37 ;
} else {
F_31 ( L_2 ) ;
return - 1 ;
}
return 0 ;
V_47:
return V_28 ;
}
static int F_32 ( struct V_2 * V_4 ,
struct V_51 * V_52 )
{
struct V_15 * V_16 = V_4 -> V_16 ;
T_2 V_53 = V_52 -> V_54 - V_52 -> V_55 ;
V_52 -> V_55 = ( unsigned long ) V_16 -> V_25 ;
V_52 -> V_54 = V_52 -> V_55 + V_53 ;
V_52 -> V_56 |= V_57 ;
return 0 ;
}
static int F_33 ( struct V_2 * V_4 , int V_58 ,
T_1 V_59 , void * V_39 , T_1 V_60 )
{
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_15 * V_16 = V_4 -> V_16 ;
unsigned int V_61 = V_16 -> V_62 / 8 ;
struct V_11 * V_12 ;
unsigned int V_63 ;
void * V_64 , * V_65 ;
V_12 = F_5 ( V_8 -> V_13 , V_4 ) ;
if ( V_12 -> V_14 ) {
if ( V_4 -> V_23 == V_24 ) {
V_64 = V_39 ;
V_65 = V_16 -> V_25 ;
V_65 += V_59 * V_61 * 8 ;
while ( V_60 -- ) {
for ( V_63 = 0 ; V_63 < V_16 -> V_21 ; V_63 ++ ) {
memcpy ( V_65 + V_12 -> V_66 [ V_63 ] *
V_61 , V_64 , V_61 ) ;
V_64 += V_61 ;
}
V_65 += 8 * V_61 ;
}
} else {
V_64 = V_16 -> V_25 ;
V_64 += V_59 * V_61 * 8 ;
V_65 = V_39 ;
while ( V_60 -- ) {
for ( V_63 = 0 ; V_63 < V_16 -> V_21 ; V_63 ++ ) {
memcpy ( V_65 , V_64 + V_12 -> V_66 [ V_63 ] *
V_61 , V_61 ) ;
V_65 += V_61 ;
}
V_64 += 8 * V_61 ;
}
}
} else {
if ( V_4 -> V_23 == V_24 ) {
V_64 = V_39 ;
V_65 = V_16 -> V_25 ;
V_65 += F_11 ( V_16 , V_59 ) ;
} else {
V_64 = V_16 -> V_25 ;
V_64 += F_11 ( V_16 , V_59 ) ;
V_65 = V_39 ;
}
memcpy ( V_65 , V_64 , F_11 ( V_16 , V_60 ) ) ;
}
return 0 ;
}
static int F_34 ( struct V_2 * V_4 ,
int V_58 , T_1 V_59 , T_1 V_60 )
{
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_15 * V_16 = V_4 -> V_16 ;
unsigned int V_61 = V_16 -> V_62 / 8 ;
void * V_39 = V_16 -> V_25 ;
struct V_11 * V_12 ;
unsigned int V_67 , V_68 ;
V_12 = F_5 ( V_8 -> V_13 , V_4 ) ;
if ( V_12 -> V_14 ) {
V_67 = V_59 * 8 * V_61 ;
V_68 = V_60 * 8 ;
} else {
V_67 = F_11 ( V_16 , V_59 ) ;
V_68 = V_60 * V_16 -> V_21 ;
}
F_35 ( V_16 -> V_69 , V_39 + V_67 , V_68 ) ;
return 0 ;
}
static int F_36 ( struct V_7 * V_8 )
{
struct V_70 * V_71 = V_8 -> V_71 -> V_70 ;
T_2 V_53 = V_41 . V_43 ;
int V_28 ;
F_12 ( L_1 , V_22 ) ;
V_28 = F_37 ( V_71 -> V_72 , F_38 ( 32 ) ) ;
if ( V_28 )
return V_28 ;
return F_39 ( V_8 -> V_3 ,
V_73 , V_71 -> V_72 , V_53 , V_53 ) ;
}
static int F_40 ( struct V_74 * V_75 )
{
return F_41 ( & V_75 -> V_72 , & V_76 ) ;
}
static int F_42 ( struct V_74 * V_75 )
{
F_43 ( & V_75 -> V_72 ) ;
return 0 ;
}
