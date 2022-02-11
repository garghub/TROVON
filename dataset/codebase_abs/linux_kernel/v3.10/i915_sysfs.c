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
V_36 = V_5 -> V_47 . V_49 * V_50 ;
F_15 ( & V_5 -> V_47 . V_48 ) ;
return snprintf ( V_12 , V_15 , L_3 , V_36 ) ;
}
static T_3 F_23 ( struct V_8 * V_9 , struct V_10 * V_11 , char * V_12 )
{
struct V_13 * V_46 = F_6 ( V_9 , struct V_13 , V_9 ) ;
struct V_1 * V_2 = V_46 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_36 ;
F_22 ( & V_5 -> V_47 . V_48 ) ;
V_36 = V_5 -> V_47 . V_51 * V_50 ;
F_15 ( & V_5 -> V_47 . V_48 ) ;
return snprintf ( V_12 , V_15 , L_3 , V_36 ) ;
}
static T_3 F_24 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
const char * V_12 , T_5 V_32 )
{
struct V_13 * V_46 = F_6 ( V_9 , struct V_13 , V_9 ) ;
struct V_1 * V_2 = V_46 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_52 , V_53 , V_54 , V_55 , V_56 ;
T_3 V_36 ;
V_36 = F_25 ( V_12 , 0 , & V_52 ) ;
if ( V_36 )
return V_36 ;
V_52 /= V_50 ;
F_22 ( & V_5 -> V_47 . V_48 ) ;
V_53 = F_3 ( V_57 ) ;
V_54 = V_5 -> V_47 . V_54 ;
V_56 = ( V_53 & 0xff ) ;
V_55 = ( ( V_53 & 0xff0000 ) >> 16 ) ;
if ( V_52 < V_55 || V_52 > V_54 || V_52 < V_5 -> V_47 . V_58 ) {
F_15 ( & V_5 -> V_47 . V_48 ) ;
return - V_24 ;
}
if ( V_52 > V_56 )
F_26 ( L_4 ,
V_52 * V_50 ) ;
if ( V_5 -> V_47 . V_49 > V_52 )
F_27 ( V_5 -> V_2 , V_52 ) ;
V_5 -> V_47 . V_51 = V_52 ;
F_15 ( & V_5 -> V_47 . V_48 ) ;
return V_32 ;
}
static T_3 F_28 ( struct V_8 * V_9 , struct V_10 * V_11 , char * V_12 )
{
struct V_13 * V_46 = F_6 ( V_9 , struct V_13 , V_9 ) ;
struct V_1 * V_2 = V_46 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_36 ;
F_22 ( & V_5 -> V_47 . V_48 ) ;
V_36 = V_5 -> V_47 . V_58 * V_50 ;
F_15 ( & V_5 -> V_47 . V_48 ) ;
return snprintf ( V_12 , V_15 , L_3 , V_36 ) ;
}
static T_3 F_29 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
const char * V_12 , T_5 V_32 )
{
struct V_13 * V_46 = F_6 ( V_9 , struct V_13 , V_9 ) ;
struct V_1 * V_2 = V_46 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_52 , V_53 , V_54 , V_55 ;
T_3 V_36 ;
V_36 = F_25 ( V_12 , 0 , & V_52 ) ;
if ( V_36 )
return V_36 ;
V_52 /= V_50 ;
F_22 ( & V_5 -> V_47 . V_48 ) ;
V_53 = F_3 ( V_57 ) ;
V_54 = V_5 -> V_47 . V_54 ;
V_55 = ( ( V_53 & 0xff0000 ) >> 16 ) ;
if ( V_52 < V_55 || V_52 > V_54 || V_52 > V_5 -> V_47 . V_51 ) {
F_15 ( & V_5 -> V_47 . V_48 ) ;
return - V_24 ;
}
if ( V_5 -> V_47 . V_49 < V_52 )
F_27 ( V_5 -> V_2 , V_52 ) ;
V_5 -> V_47 . V_58 = V_52 ;
F_15 ( & V_5 -> V_47 . V_48 ) ;
return V_32 ;
}
static T_3 F_30 ( struct V_8 * V_9 , struct V_10 * V_11 , char * V_12 )
{
struct V_13 * V_46 = F_6 ( V_9 , struct V_13 , V_9 ) ;
struct V_1 * V_2 = V_46 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_52 , V_53 ;
T_3 V_36 ;
V_36 = F_31 ( & V_2 -> V_40 ) ;
if ( V_36 )
return V_36 ;
V_53 = F_3 ( V_57 ) ;
F_15 ( & V_2 -> V_40 ) ;
if ( V_11 == & V_59 ) {
V_52 = ( ( V_53 & 0x0000ff ) >> 0 ) * V_50 ;
} else if ( V_11 == & V_60 ) {
V_52 = ( ( V_53 & 0x00ff00 ) >> 8 ) * V_50 ;
} else if ( V_11 == & V_61 ) {
V_52 = ( ( V_53 & 0xff0000 ) >> 16 ) * V_50 ;
} else {
F_32 () ;
}
return snprintf ( V_12 , V_15 , L_3 , V_52 ) ;
}
void F_33 ( struct V_1 * V_2 )
{
int V_36 ;
#ifdef F_34
if ( F_35 ( V_2 ) -> V_62 >= 6 ) {
V_36 = F_36 ( & V_2 -> V_63 -> V_9 . V_30 ,
& V_64 ) ;
if ( V_36 )
F_37 ( L_5 ) ;
}
#endif
if ( F_11 ( V_2 ) ) {
V_36 = F_38 ( & V_2 -> V_63 -> V_9 , & V_65 ) ;
if ( V_36 )
F_37 ( L_6 ) ;
}
if ( F_35 ( V_2 ) -> V_62 >= 6 ) {
V_36 = F_39 ( & V_2 -> V_63 -> V_9 . V_30 , V_66 ) ;
if ( V_36 )
F_37 ( L_7 ) ;
}
}
void F_40 ( struct V_1 * V_2 )
{
F_41 ( & V_2 -> V_63 -> V_9 . V_30 , V_66 ) ;
F_42 ( & V_2 -> V_63 -> V_9 , & V_65 ) ;
#ifdef F_34
F_43 ( & V_2 -> V_63 -> V_9 . V_30 , & V_64 ) ;
#endif
}
