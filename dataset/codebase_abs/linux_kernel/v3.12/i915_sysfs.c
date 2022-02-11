static T_1 F_1 ( struct V_1 * V_2 , const T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_2 V_7 ;
if ( ! F_2 ( V_2 ) )
return 0 ;
V_7 = F_3 ( V_3 ) * 128ULL ;
return F_4 ( V_7 , 100000 ) ;
}
static T_3
F_5 ( struct V_8 * V_9 , struct V_10 * V_11 , char * V_12 )
{
struct V_13 * V_14 = F_6 ( V_9 , struct V_13 , V_9 ) ;
return snprintf ( V_12 , V_15 , L_1 , F_2 ( V_14 -> V_2 ) ) ;
}
static T_3
F_7 ( struct V_8 * V_9 , struct V_10 * V_11 , char * V_12 )
{
struct V_13 * V_14 = F_6 ( V_9 , struct V_13 , V_9 ) ;
T_1 V_16 = F_1 ( V_14 -> V_2 , V_17 ) ;
return snprintf ( V_12 , V_15 , L_2 , V_16 ) ;
}
static T_3
F_8 ( struct V_8 * V_9 , struct V_10 * V_11 , char * V_12 )
{
struct V_13 * V_14 = F_6 ( V_9 , struct V_13 , V_9 ) ;
T_1 V_18 = F_1 ( V_14 -> V_2 , V_19 ) ;
return snprintf ( V_12 , V_15 , L_2 , V_18 ) ;
}
static T_3
F_9 ( struct V_8 * V_9 , struct V_10 * V_11 , char * V_12 )
{
struct V_13 * V_14 = F_6 ( V_9 , struct V_13 , V_9 ) ;
T_1 V_20 = F_1 ( V_14 -> V_2 , V_21 ) ;
return snprintf ( V_12 , V_15 , L_2 , V_20 ) ;
}
static int F_10 ( struct V_1 * V_2 , T_4 V_22 )
{
if ( ! F_11 ( V_2 ) )
return - V_23 ;
if ( V_22 % 4 != 0 )
return - V_24 ;
if ( V_22 >= V_25 )
return - V_26 ;
return 0 ;
}
static T_3
F_12 ( struct V_27 * V_28 , struct V_29 * V_30 ,
struct V_31 * V_11 , char * V_12 ,
T_4 V_22 , T_5 V_32 )
{
struct V_8 * V_2 = F_6 ( V_30 , struct V_8 , V_30 ) ;
struct V_13 * V_14 = F_6 ( V_2 , struct V_13 , V_9 ) ;
struct V_1 * V_33 = V_14 -> V_2 ;
struct V_4 * V_5 = V_33 -> V_6 ;
T_6 V_34 ;
int V_35 , V_36 ;
V_36 = F_10 ( V_33 , V_22 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_13 ( V_33 ) ;
if ( V_36 )
return V_36 ;
V_34 = F_3 ( V_37 ) ;
F_14 ( V_37 , V_34 & ~ V_38 ) ;
for ( V_35 = V_22 ; V_32 >= 4 && V_35 < V_25 ; V_35 += 4 , V_32 -= 4 )
* ( ( T_6 * ) ( & V_12 [ V_35 ] ) ) = F_3 ( V_39 + V_35 ) ;
F_14 ( V_37 , V_34 ) ;
F_15 ( & V_33 -> V_40 ) ;
return V_35 - V_22 ;
}
static T_3
F_16 ( struct V_27 * V_28 , struct V_29 * V_30 ,
struct V_31 * V_11 , char * V_12 ,
T_4 V_22 , T_5 V_32 )
{
struct V_8 * V_2 = F_6 ( V_30 , struct V_8 , V_30 ) ;
struct V_13 * V_14 = F_6 ( V_2 , struct V_13 , V_9 ) ;
struct V_1 * V_33 = V_14 -> V_2 ;
struct V_4 * V_5 = V_33 -> V_6 ;
T_1 * V_41 = NULL ;
int V_36 ;
V_36 = F_10 ( V_33 , V_22 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_13 ( V_33 ) ;
if ( V_36 )
return V_36 ;
if ( ! V_5 -> V_42 . V_43 ) {
V_41 = F_17 ( V_25 , V_44 ) ;
if ( ! V_41 ) {
F_15 ( & V_33 -> V_40 ) ;
return - V_45 ;
}
}
V_36 = F_18 ( V_33 ) ;
if ( V_36 ) {
F_19 ( V_41 ) ;
F_15 ( & V_33 -> V_40 ) ;
return V_36 ;
}
if ( V_41 )
V_5 -> V_42 . V_43 = V_41 ;
memcpy ( V_5 -> V_42 . V_43 + ( V_22 / 4 ) ,
V_12 + ( V_22 / 4 ) ,
V_32 ) ;
F_20 ( V_33 ) ;
F_15 ( & V_33 -> V_40 ) ;
return V_32 ;
}
static T_3 F_21 ( struct V_8 * V_9 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_13 * V_46 = F_6 ( V_9 , struct V_13 , V_9 ) ;
struct V_1 * V_2 = V_46 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_36 ;
F_22 ( & V_5 -> V_47 . V_48 ) ;
if ( F_23 ( V_5 -> V_2 ) ) {
T_1 V_49 ;
V_49 = F_24 ( V_5 , V_50 ) ;
V_36 = F_25 ( V_5 -> V_51 , ( V_49 >> 8 ) & 0xff ) ;
} else {
V_36 = V_5 -> V_47 . V_52 * V_53 ;
}
F_15 ( & V_5 -> V_47 . V_48 ) ;
return snprintf ( V_12 , V_15 , L_3 , V_36 ) ;
}
static T_3 F_26 ( struct V_8 * V_9 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_13 * V_46 = F_6 ( V_9 , struct V_13 , V_9 ) ;
struct V_1 * V_2 = V_46 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
return snprintf ( V_12 , V_15 , L_3 ,
F_25 ( V_5 -> V_51 ,
V_5 -> V_47 . V_54 ) ) ;
}
static T_3 F_27 ( struct V_8 * V_9 , struct V_10 * V_11 , char * V_12 )
{
struct V_13 * V_46 = F_6 ( V_9 , struct V_13 , V_9 ) ;
struct V_1 * V_2 = V_46 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_36 ;
F_22 ( & V_5 -> V_47 . V_48 ) ;
if ( F_23 ( V_5 -> V_2 ) )
V_36 = F_25 ( V_5 -> V_51 , V_5 -> V_47 . V_55 ) ;
else
V_36 = V_5 -> V_47 . V_55 * V_53 ;
F_15 ( & V_5 -> V_47 . V_48 ) ;
return snprintf ( V_12 , V_15 , L_3 , V_36 ) ;
}
static T_3 F_28 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
const char * V_12 , T_5 V_32 )
{
struct V_13 * V_46 = F_6 ( V_9 , struct V_13 , V_9 ) ;
struct V_1 * V_2 = V_46 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_56 , V_57 , V_58 , V_59 , V_60 ;
T_3 V_36 ;
V_36 = F_29 ( V_12 , 0 , & V_56 ) ;
if ( V_36 )
return V_36 ;
F_22 ( & V_5 -> V_47 . V_48 ) ;
if ( F_23 ( V_5 -> V_2 ) ) {
V_56 = F_30 ( V_5 -> V_51 , V_56 ) ;
V_58 = F_31 ( V_5 ) ;
V_59 = F_32 ( V_5 ) ;
V_60 = V_58 ;
} else {
V_56 /= V_53 ;
V_57 = F_3 ( V_61 ) ;
V_58 = V_5 -> V_47 . V_58 ;
V_60 = ( V_57 & 0xff ) ;
V_59 = ( ( V_57 & 0xff0000 ) >> 16 ) ;
}
if ( V_56 < V_59 || V_56 > V_58 ||
V_56 < V_5 -> V_47 . V_62 ) {
F_15 ( & V_5 -> V_47 . V_48 ) ;
return - V_24 ;
}
if ( V_56 > V_60 )
F_33 ( L_4 ,
V_56 * V_53 ) ;
if ( V_5 -> V_47 . V_52 > V_56 ) {
if ( F_23 ( V_5 -> V_2 ) )
F_34 ( V_5 -> V_2 , V_56 ) ;
else
F_35 ( V_5 -> V_2 , V_56 ) ;
}
V_5 -> V_47 . V_55 = V_56 ;
F_15 ( & V_5 -> V_47 . V_48 ) ;
return V_32 ;
}
static T_3 F_36 ( struct V_8 * V_9 , struct V_10 * V_11 , char * V_12 )
{
struct V_13 * V_46 = F_6 ( V_9 , struct V_13 , V_9 ) ;
struct V_1 * V_2 = V_46 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_36 ;
F_22 ( & V_5 -> V_47 . V_48 ) ;
if ( F_23 ( V_5 -> V_2 ) )
V_36 = F_25 ( V_5 -> V_51 , V_5 -> V_47 . V_62 ) ;
else
V_36 = V_5 -> V_47 . V_62 * V_53 ;
F_15 ( & V_5 -> V_47 . V_48 ) ;
return snprintf ( V_12 , V_15 , L_3 , V_36 ) ;
}
static T_3 F_37 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
const char * V_12 , T_5 V_32 )
{
struct V_13 * V_46 = F_6 ( V_9 , struct V_13 , V_9 ) ;
struct V_1 * V_2 = V_46 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_56 , V_57 , V_58 , V_59 ;
T_3 V_36 ;
V_36 = F_29 ( V_12 , 0 , & V_56 ) ;
if ( V_36 )
return V_36 ;
F_22 ( & V_5 -> V_47 . V_48 ) ;
if ( F_23 ( V_2 ) ) {
V_56 = F_30 ( V_5 -> V_51 , V_56 ) ;
V_58 = F_31 ( V_5 ) ;
V_59 = F_32 ( V_5 ) ;
} else {
V_56 /= V_53 ;
V_57 = F_3 ( V_61 ) ;
V_58 = V_5 -> V_47 . V_58 ;
V_59 = ( ( V_57 & 0xff0000 ) >> 16 ) ;
}
if ( V_56 < V_59 || V_56 > V_58 || V_56 > V_5 -> V_47 . V_55 ) {
F_15 ( & V_5 -> V_47 . V_48 ) ;
return - V_24 ;
}
if ( V_5 -> V_47 . V_52 < V_56 ) {
if ( F_23 ( V_2 ) )
F_34 ( V_2 , V_56 ) ;
else
F_35 ( V_5 -> V_2 , V_56 ) ;
}
V_5 -> V_47 . V_62 = V_56 ;
F_15 ( & V_5 -> V_47 . V_48 ) ;
return V_32 ;
}
static T_3 F_38 ( struct V_8 * V_9 , struct V_10 * V_11 , char * V_12 )
{
struct V_13 * V_46 = F_6 ( V_9 , struct V_13 , V_9 ) ;
struct V_1 * V_2 = V_46 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_56 , V_57 ;
T_3 V_36 ;
V_36 = F_39 ( & V_2 -> V_40 ) ;
if ( V_36 )
return V_36 ;
V_57 = F_3 ( V_61 ) ;
F_15 ( & V_2 -> V_40 ) ;
if ( V_11 == & V_63 ) {
V_56 = ( ( V_57 & 0x0000ff ) >> 0 ) * V_53 ;
} else if ( V_11 == & V_64 ) {
V_56 = ( ( V_57 & 0x00ff00 ) >> 8 ) * V_53 ;
} else if ( V_11 == & V_65 ) {
V_56 = ( ( V_57 & 0xff0000 ) >> 16 ) * V_53 ;
} else {
F_40 () ;
}
return snprintf ( V_12 , V_15 , L_3 , V_56 ) ;
}
static T_3 F_41 ( struct V_27 * V_28 , struct V_29 * V_30 ,
struct V_31 * V_11 , char * V_12 ,
T_4 V_66 , T_5 V_32 )
{
struct V_8 * V_9 = F_6 ( V_30 , struct V_8 , V_30 ) ;
struct V_13 * V_46 = F_6 ( V_9 , struct V_13 , V_9 ) ;
struct V_1 * V_2 = V_46 -> V_2 ;
struct V_67 V_68 ;
struct V_69 V_70 ;
T_3 V_71 = 0 ;
int V_36 ;
memset ( & V_68 , 0 , sizeof( V_68 ) ) ;
V_36 = F_42 ( & V_70 , V_32 , V_66 ) ;
if ( V_36 )
return V_36 ;
V_68 . V_2 = V_2 ;
F_43 ( V_2 , & V_68 ) ;
V_36 = F_44 ( & V_70 , & V_68 ) ;
if ( V_36 )
goto V_72;
V_71 = V_32 < V_70 . V_73 ? V_32 : V_70 . V_73 ;
memcpy ( V_12 , V_70 . V_12 , V_71 ) ;
V_72:
F_45 ( & V_68 ) ;
F_46 ( & V_70 ) ;
return V_36 ? : V_71 ;
}
static T_3 F_47 ( struct V_27 * V_27 , struct V_29 * V_30 ,
struct V_31 * V_11 , char * V_12 ,
T_4 V_66 , T_5 V_32 )
{
struct V_8 * V_9 = F_6 ( V_30 , struct V_8 , V_30 ) ;
struct V_13 * V_46 = F_6 ( V_9 , struct V_13 , V_9 ) ;
struct V_1 * V_2 = V_46 -> V_2 ;
int V_36 ;
F_48 ( L_5 ) ;
V_36 = F_39 ( & V_2 -> V_40 ) ;
if ( V_36 )
return V_36 ;
F_49 ( V_2 ) ;
F_15 ( & V_2 -> V_40 ) ;
return V_32 ;
}
void F_50 ( struct V_1 * V_2 )
{
int V_36 ;
#ifdef F_51
if ( F_52 ( V_2 ) -> V_74 >= 6 ) {
V_36 = F_53 ( & V_2 -> V_75 -> V_9 . V_30 ,
& V_76 ) ;
if ( V_36 )
F_54 ( L_6 ) ;
}
#endif
if ( F_11 ( V_2 ) ) {
V_36 = F_55 ( & V_2 -> V_75 -> V_9 , & V_77 ) ;
if ( V_36 )
F_54 ( L_7 ) ;
}
V_36 = 0 ;
if ( F_23 ( V_2 ) )
V_36 = F_56 ( & V_2 -> V_75 -> V_9 . V_30 , V_78 ) ;
else if ( F_52 ( V_2 ) -> V_74 >= 6 )
V_36 = F_56 ( & V_2 -> V_75 -> V_9 . V_30 , V_79 ) ;
if ( V_36 )
F_54 ( L_8 ) ;
V_36 = F_57 ( & V_2 -> V_75 -> V_9 . V_30 ,
& V_80 ) ;
if ( V_36 )
F_54 ( L_9 ) ;
}
void F_58 ( struct V_1 * V_2 )
{
F_59 ( & V_2 -> V_75 -> V_9 . V_30 , & V_80 ) ;
if ( F_23 ( V_2 ) )
F_60 ( & V_2 -> V_75 -> V_9 . V_30 , V_78 ) ;
else
F_60 ( & V_2 -> V_75 -> V_9 . V_30 , V_79 ) ;
F_61 ( & V_2 -> V_75 -> V_9 , & V_77 ) ;
#ifdef F_51
F_62 ( & V_2 -> V_75 -> V_9 . V_30 , & V_76 ) ;
#endif
}
