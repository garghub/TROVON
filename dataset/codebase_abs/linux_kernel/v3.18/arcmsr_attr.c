static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 ,
T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( V_4 , struct V_10 , V_4 ) ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
T_4 * V_17 ;
T_5 V_18 = 0 ;
unsigned long V_19 ;
if ( ! F_4 ( V_20 ) )
return - V_21 ;
V_17 = ( T_4 * ) V_7 ;
F_5 ( & V_15 -> V_22 , V_19 ) ;
if ( V_15 -> V_23 != V_15 -> V_24 ) {
unsigned int V_25 = V_15 -> V_23 ;
unsigned int V_26 = V_15 -> V_24 ;
unsigned int V_27 = F_6 ( V_26 , V_25 , V_28 ) ;
V_18 = F_7 ( V_26 , V_25 , V_28 ) ;
if ( V_18 > V_29 )
V_18 = V_29 ;
if ( V_18 <= V_27 )
memcpy ( V_17 , V_15 -> V_30 + V_25 , V_18 ) ;
else {
memcpy ( V_17 , V_15 -> V_30 + V_25 , V_27 ) ;
memcpy ( V_17 + V_27 , V_15 -> V_30 , V_18 - V_27 ) ;
}
V_15 -> V_23 = ( V_15 -> V_23 + V_18 ) % V_28 ;
}
if ( V_15 -> V_31 & V_32 ) {
struct V_33 T_6 * V_34 ;
V_15 -> V_31 &= ~ V_32 ;
V_34 = F_8 ( V_15 ) ;
if ( F_9 ( V_15 , V_34 ) == 0 )
V_15 -> V_31 |= V_32 ;
}
F_10 ( & V_15 -> V_22 , V_19 ) ;
return V_18 ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 ,
T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( V_4 , struct V_10 , V_4 ) ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
T_5 V_35 , V_36 ;
T_4 * V_37 , * V_38 ;
unsigned long V_19 ;
if ( ! F_4 ( V_20 ) )
return - V_21 ;
if ( V_9 > V_29 )
return - V_39 ;
V_38 = ( T_4 * ) V_7 ;
V_35 = ( T_5 ) V_9 ;
F_5 ( & V_15 -> V_40 , V_19 ) ;
if ( V_15 -> V_41 != V_15 -> V_42 ) {
F_12 ( V_15 ) ;
F_10 ( & V_15 -> V_40 , V_19 ) ;
return 0 ;
} else {
V_37 = & V_15 -> V_43 [ V_15 -> V_41 ] ;
V_36 = V_28 - V_15 -> V_41 ;
if ( V_35 > V_36 ) {
memcpy ( V_37 , V_38 , V_36 ) ;
V_38 += V_36 ;
V_35 -= V_36 ;
V_15 -> V_41 = 0 ;
V_37 = V_15 -> V_43 ;
}
memcpy ( V_37 , V_38 , V_35 ) ;
V_15 -> V_41 += V_35 ;
V_15 -> V_41 %= V_28 ;
if ( V_15 -> V_31 & V_44 ) {
V_15 -> V_31 &=
~ V_44 ;
F_12 ( V_15 ) ;
}
F_10 ( & V_15 -> V_40 , V_19 ) ;
return V_9 ;
}
}
static T_1 F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 ,
T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( V_4 , struct V_10 , V_4 ) ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_13 -> V_16 ;
T_4 * V_37 ;
unsigned long V_19 ;
if ( ! F_4 ( V_20 ) )
return - V_21 ;
F_14 ( V_15 ) ;
V_15 -> V_31 |=
( V_44
| V_45
| V_46 ) ;
F_5 ( & V_15 -> V_22 , V_19 ) ;
V_15 -> V_23 = 0 ;
V_15 -> V_24 = 0 ;
F_10 ( & V_15 -> V_22 , V_19 ) ;
F_5 ( & V_15 -> V_40 , V_19 ) ;
V_15 -> V_42 = 0 ;
V_15 -> V_41 = 0 ;
F_10 ( & V_15 -> V_40 , V_19 ) ;
V_37 = V_15 -> V_30 ;
memset ( V_37 , 0 , sizeof ( struct V_33 ) ) ;
V_37 = V_15 -> V_43 ;
memset ( V_37 , 0 , sizeof ( struct V_33 ) ) ;
return 1 ;
}
int F_15 ( struct V_14 * V_15 )
{
struct V_12 * V_13 = V_15 -> V_13 ;
int error ;
error = F_16 ( & V_13 -> V_47 . V_4 , & V_48 ) ;
if ( error ) {
F_17 ( V_49 L_1 ) ;
goto V_50;
}
error = F_16 ( & V_13 -> V_47 . V_4 , & V_51 ) ;
if ( error ) {
F_17 ( V_49 L_2 ) ;
goto V_52;
}
error = F_16 ( & V_13 -> V_47 . V_4 , & V_53 ) ;
if ( error ) {
F_17 ( V_49 L_3 ) ;
goto V_54;
}
return 0 ;
V_54:
F_18 ( & V_13 -> V_47 . V_4 , & V_51 ) ;
V_52:
F_18 ( & V_13 -> V_47 . V_4 , & V_48 ) ;
V_50:
return error ;
}
void F_19 ( struct V_14 * V_15 )
{
struct V_12 * V_13 = V_15 -> V_13 ;
F_18 ( & V_13 -> V_47 . V_4 , & V_53 ) ;
F_18 ( & V_13 -> V_47 . V_4 , & V_51 ) ;
F_18 ( & V_13 -> V_47 . V_4 , & V_48 ) ;
}
static T_1
F_20 ( struct V_10 * V_11 ,
struct V_55 * V_56 , char * V_7 )
{
return snprintf ( V_7 , V_57 ,
L_4 ,
V_58 ) ;
}
static T_1
F_21 ( struct V_10 * V_11 ,
struct V_55 * V_56 , char * V_7 )
{
struct V_12 * V_13 = F_3 ( V_11 ) ;
struct V_14 * V_15 =
(struct V_14 * ) V_13 -> V_16 ;
return snprintf ( V_7 , V_57 ,
L_5 ,
F_22 ( & V_15 -> V_59 ) ) ;
}
static T_1
F_23 ( struct V_10 * V_11 ,
struct V_55 * V_56 , char * V_7 )
{
struct V_12 * V_13 = F_3 ( V_11 ) ;
struct V_14 * V_15 =
(struct V_14 * ) V_13 -> V_16 ;
return snprintf ( V_7 , V_57 ,
L_5 ,
V_15 -> V_60 ) ;
}
static T_1
F_24 ( struct V_10 * V_11 ,
struct V_55 * V_56 , char * V_7 )
{
struct V_12 * V_13 = F_3 ( V_11 ) ;
struct V_14 * V_15 =
(struct V_14 * ) V_13 -> V_16 ;
return snprintf ( V_7 , V_57 ,
L_5 ,
V_15 -> V_61 ) ;
}
static T_1
F_25 ( struct V_10 * V_11 , struct V_55 * V_56 ,
char * V_7 )
{
struct V_12 * V_13 = F_3 ( V_11 ) ;
struct V_14 * V_15 =
(struct V_14 * ) V_13 -> V_16 ;
return snprintf ( V_7 , V_57 ,
L_4 ,
V_15 -> V_62 ) ;
}
static T_1
F_26 ( struct V_10 * V_11 ,
struct V_55 * V_56 , char * V_7 )
{
struct V_12 * V_13 = F_3 ( V_11 ) ;
struct V_14 * V_15 =
(struct V_14 * ) V_13 -> V_16 ;
return snprintf ( V_7 , V_57 ,
L_4 ,
V_15 -> V_63 ) ;
}
static T_1
F_27 ( struct V_10 * V_11 ,
struct V_55 * V_56 , char * V_7 )
{
struct V_12 * V_13 = F_3 ( V_11 ) ;
struct V_14 * V_15 =
(struct V_14 * ) V_13 -> V_16 ;
return snprintf ( V_7 , V_57 ,
L_5 ,
V_15 -> V_64 ) ;
}
static T_1
F_28 ( struct V_10 * V_11 ,
struct V_55 * V_56 , char * V_7 )
{
struct V_12 * V_13 = F_3 ( V_11 ) ;
struct V_14 * V_15 =
(struct V_14 * ) V_13 -> V_16 ;
return snprintf ( V_7 , V_57 ,
L_5 ,
V_15 -> V_65 ) ;
}
static T_1
F_29 ( struct V_10 * V_11 ,
struct V_55 * V_56 , char * V_7 )
{
struct V_12 * V_13 = F_3 ( V_11 ) ;
struct V_14 * V_15 =
(struct V_14 * ) V_13 -> V_16 ;
return snprintf ( V_7 , V_57 ,
L_5 ,
V_15 -> V_66 ) ;
}
static T_1
F_30 ( struct V_10 * V_11 ,
struct V_55 * V_56 , char * V_7 )
{
struct V_12 * V_13 = F_3 ( V_11 ) ;
struct V_14 * V_15 =
(struct V_14 * ) V_13 -> V_16 ;
return snprintf ( V_7 , V_57 ,
L_5 ,
V_15 -> V_67 ) ;
}
