static inline void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
switch ( V_3 ) {
case V_6 :
V_5 -> V_7 . V_8 ++ ;
break;
case V_9 :
V_5 -> V_7 . V_10 ++ ;
break;
case V_11 :
V_5 -> V_7 . V_12 ++ ;
break;
}
}
static inline struct V_13 * F_2 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_15 ;
if ( ! V_14 )
V_14 = V_2 -> V_16 -> V_17 ( V_2 ) ;
else
V_2 -> V_15 = NULL ;
return V_14 ;
}
static void F_3 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_4 ( V_19 , struct V_1 , V_20 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_13 * V_14 ;
do {
F_5 ( V_23 , & V_2 -> V_24 ) ;
while ( ( V_14 = F_2 ( V_2 ) ) ) {
int V_25 ;
V_25 = F_6 ( V_22 ,
V_14 -> V_26 , V_14 -> V_25 ) ;
V_5 -> V_7 . V_27 += V_25 ;
F_7 ( V_14 , V_25 ) ;
if ( V_14 -> V_25 ) {
V_2 -> V_15 = V_14 ;
break;
}
F_1 ( V_2 , F_8 ( V_14 ) ) ;
F_9 ( V_14 ) ;
}
} while( F_10 ( V_23 , & V_2 -> V_24 ) );
F_5 ( V_28 , & V_2 -> V_24 ) ;
}
static int F_11 ( struct V_4 * V_5 )
{
F_12 ( L_1 , V_5 -> V_29 , V_5 ) ;
return 0 ;
}
static int F_13 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_14 ( V_5 ) ;
F_12 ( L_2 , V_5 , V_2 -> V_22 ) ;
if ( V_2 -> V_15 ) {
F_9 ( V_2 -> V_15 ) ; V_2 -> V_15 = NULL ;
}
F_15 ( V_2 -> V_22 ) ;
if ( F_10 ( V_30 , & V_2 -> V_31 ) )
V_2 -> V_16 -> V_32 ( V_2 ) ;
return 0 ;
}
static int F_16 ( struct V_4 * V_5 )
{
F_12 ( L_3 , V_5 ) ;
F_13 ( V_5 ) ;
V_5 -> V_32 = NULL ;
return 0 ;
}
static int F_17 ( struct V_4 * V_5 , struct V_13 * V_14 )
{
struct V_1 * V_2 = F_14 ( V_5 ) ;
F_12 ( L_4 , V_5 -> V_29 , F_8 ( V_14 ) ,
V_14 -> V_25 ) ;
V_2 -> V_16 -> V_33 ( V_2 , V_14 ) ;
F_18 ( V_2 ) ;
return 0 ;
}
static int F_19 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_14 ( V_5 ) ;
struct V_34 * V_35 ;
struct V_13 * V_14 ;
unsigned int V_36 ;
int V_37 ;
if ( V_2 -> V_38 )
V_36 = V_2 -> V_38 ;
else if ( V_2 -> V_16 -> V_38 )
V_36 = V_2 -> V_16 -> V_38 ;
else
V_36 = 0 ;
if ( V_36 )
F_20 ( V_2 -> V_22 , V_36 ) ;
if ( V_2 -> V_39 )
V_36 = V_2 -> V_39 ;
else if ( V_2 -> V_16 -> V_39 )
V_36 = V_2 -> V_16 -> V_39 ;
else
V_36 = 0 ;
if ( V_2 -> V_16 -> V_40 && V_36 ) {
V_37 = V_2 -> V_16 -> V_40 ( V_2 , V_36 ) ;
if ( V_37 )
F_21 ( L_5 , V_5 -> V_29 ) ;
else
F_20 ( V_2 -> V_22 , V_36 ) ;
}
if ( V_2 -> V_16 -> V_41 )
return V_2 -> V_16 -> V_41 ( V_2 ) ;
if ( ! F_10 ( V_42 , & V_2 -> V_43 ) )
return 0 ;
V_14 = F_22 ( V_5 , V_44 , 0 , NULL ,
V_45 ) ;
if ( F_23 ( V_14 ) ) {
F_21 ( L_6 ,
V_5 -> V_29 , F_24 ( V_14 ) ) ;
return 0 ;
}
if ( V_14 -> V_25 != sizeof( * V_35 ) ) {
F_21 ( L_7 ,
V_5 -> V_29 ) ;
}
F_9 ( V_14 ) ;
return 0 ;
}
static void F_25 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_26 ( V_22 ) ;
F_12 ( L_8 ) ;
if ( ! V_2 || V_22 != V_2 -> V_22 ) {
F_27 ( 1 ) ;
return;
}
if ( F_10 ( V_30 , & V_2 -> V_31 ) )
F_18 ( V_2 ) ;
}
static int F_28 ( struct V_21 * V_22 , const T_1 * V_26 ,
T_2 V_46 )
{
struct V_1 * V_2 = F_26 ( V_22 ) ;
if ( ! V_2 || V_22 != V_2 -> V_22 ) {
F_27 ( 1 ) ;
return 0 ;
}
if ( ! F_10 ( V_30 , & V_2 -> V_31 ) )
return 0 ;
V_2 -> V_16 -> V_47 ( V_2 , V_26 , V_46 ) ;
if ( V_2 -> V_5 )
V_2 -> V_5 -> V_7 . V_48 += V_46 ;
return V_46 ;
}
int F_29 ( struct V_1 * V_2 ,
const struct V_49 * V_50 )
{
int V_37 ;
struct V_4 * V_5 ;
F_12 ( L_8 ) ;
F_30 ( V_2 -> V_22 , & V_51 ) ;
V_37 = V_50 -> V_52 ( V_2 ) ;
if ( V_37 )
return V_37 ;
V_2 -> V_16 = V_50 ;
F_31 ( V_30 , & V_2 -> V_31 ) ;
V_5 = F_32 () ;
if ( ! V_5 ) {
F_21 ( L_9 ) ;
V_37 = - V_53 ;
goto V_54;
}
V_2 -> V_5 = V_5 ;
V_5 -> V_55 = V_56 ;
F_33 ( V_5 , V_2 ) ;
F_34 ( & V_2 -> V_20 , F_3 ) ;
if ( V_2 -> V_16 -> V_41 )
V_5 -> V_57 = V_2 -> V_16 -> V_57 ;
V_5 -> V_52 = F_11 ;
V_5 -> V_58 = F_16 ;
V_5 -> V_32 = F_13 ;
V_5 -> V_59 = F_17 ;
V_5 -> V_41 = F_19 ;
F_35 ( V_5 , & V_2 -> V_22 -> V_60 ) ;
if ( F_10 ( V_61 , & V_2 -> V_43 ) )
F_31 ( V_62 , & V_5 -> V_63 ) ;
if ( F_10 ( V_64 , & V_2 -> V_43 ) )
F_31 ( V_65 , & V_5 -> V_63 ) ;
if ( ! F_10 ( V_66 , & V_2 -> V_43 ) )
F_31 ( V_67 , & V_5 -> V_63 ) ;
if ( F_10 ( V_68 , & V_2 -> V_43 ) )
V_5 -> V_69 = V_70 ;
else
V_5 -> V_69 = V_71 ;
if ( F_10 ( V_72 , & V_2 -> V_43 ) )
return 0 ;
if ( F_36 ( V_5 ) < 0 ) {
F_21 ( L_10 ) ;
V_37 = - V_73 ;
goto V_74;
}
F_31 ( V_75 , & V_2 -> V_31 ) ;
return 0 ;
V_74:
F_37 ( V_5 ) ;
V_54:
F_5 ( V_30 , & V_2 -> V_31 ) ;
V_50 -> V_58 ( V_2 ) ;
return V_37 ;
}
void F_38 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
F_39 ( V_5 ) ;
F_37 ( V_5 ) ;
F_40 ( & V_2 -> V_20 ) ;
V_2 -> V_16 -> V_58 ( V_2 ) ;
}
