static int F_1 ( double V_1 , bool V_2 )
{
if ( V_2 )
return V_3 ;
if ( V_1 >= V_4 )
return V_5 ;
if ( V_1 >= V_6 )
return V_7 ;
return V_8 ;
}
void F_2 ( struct V_9 * T_1 V_10 , int V_11 )
{
F_3 ( V_11 ) ;
}
void F_4 ( struct V_9 * T_1 ,
double V_1 , bool V_2 )
{
int V_11 = F_1 ( V_1 , V_2 ) ;
F_2 ( T_1 , V_11 ) ;
}
void F_5 ( struct V_9 * T_1 , int V_12 , int V_13 )
{
F_6 ( T_1 -> V_12 + V_12 , T_1 -> V_13 + V_13 ) ;
}
void F_7 ( struct V_9 * T_1 , T_2 V_14 , int V_15 )
{
struct V_16 * V_17 = T_1 -> V_18 ;
struct V_16 * V_19 ;
switch ( V_15 ) {
case V_20 :
V_19 = V_17 -> V_21 ;
break;
case V_22 :
V_19 = T_1 -> V_23 ;
break;
case V_24 :
V_19 = V_17 -> V_25 ;
break;
default:
return;
}
if ( V_14 > 0 ) {
while ( V_14 -- != 0 )
V_19 = V_19 -> V_21 ;
} else {
while ( V_14 ++ != 0 )
V_19 = V_19 -> V_25 ;
}
T_1 -> V_23 = V_19 ;
}
void F_8 ( struct V_9 * T_1 , T_2 V_14 , int V_15 )
{
struct V_26 * V_27 = T_1 -> V_18 ;
struct V_28 * V_29 ;
switch ( V_15 ) {
case V_20 :
V_29 = F_9 ( V_27 ) ;
break;
case V_22 :
V_29 = T_1 -> V_23 ;
break;
case V_24 :
V_29 = F_10 ( V_27 ) ;
break;
default:
return;
}
if ( V_14 > 0 ) {
while ( V_14 -- != 0 )
V_29 = F_11 ( V_29 ) ;
} else {
while ( V_14 ++ != 0 )
V_29 = F_12 ( V_29 ) ;
}
T_1 -> V_23 = V_29 ;
}
unsigned int F_13 ( struct V_9 * T_1 )
{
struct V_28 * V_29 ;
int V_30 = 0 ;
if ( T_1 -> V_23 == NULL )
T_1 -> V_23 = F_9 ( T_1 -> V_18 ) ;
V_29 = T_1 -> V_23 ;
while ( V_29 != NULL ) {
F_5 ( T_1 , V_30 , 0 ) ;
T_1 -> V_31 ( T_1 , V_29 , V_30 ) ;
if ( ++ V_30 == T_1 -> V_32 )
break;
V_29 = F_11 ( V_29 ) ;
}
return V_30 ;
}
bool F_14 ( struct V_9 * T_1 , unsigned V_30 )
{
return T_1 -> V_33 + V_30 == T_1 -> V_34 ;
}
void F_15 ( struct V_9 * T_1 )
{
int V_35 , V_36 ;
F_16 ( & V_35 , & V_36 ) ;
T_1 -> V_37 = V_35 - 1 ;
T_1 -> V_32 = V_36 - 2 ;
T_1 -> V_12 = 1 ;
T_1 -> V_13 = 0 ;
}
void F_17 ( struct V_9 * T_1 )
{
T_1 -> V_34 = T_1 -> V_33 = 0 ;
T_1 -> V_38 ( T_1 , 0 , V_20 ) ;
}
void F_18 ( struct V_9 * T_1 , int V_39 )
{
F_19 ( T_1 -> V_40 , V_39 ) ;
}
void F_20 ( struct V_9 * T_1 , int V_41 [] )
{
int V_42 = 0 ;
while ( V_41 [ V_42 ] && V_42 < 64 ) {
F_18 ( T_1 , V_41 [ V_42 ] ) ;
++ V_42 ;
}
}
void F_21 ( struct V_9 * V_43 , const char * V_44 )
{
F_6 ( 0 , 0 ) ;
F_2 ( V_43 , V_45 ) ;
F_22 ( V_44 , V_43 -> V_37 ) ;
}
void F_23 ( struct V_9 * V_43 , const char * V_44 )
{
F_24 ( & V_46 ) ;
F_21 ( V_43 , V_44 ) ;
F_25 ( & V_46 ) ;
}
int F_26 ( struct V_9 * T_1 , const char * V_44 ,
const char * V_47 , ... )
{
T_3 V_48 ;
int V_41 [] = { V_49 , V_50 , V_51 ,
V_52 , V_53 , V_54 , ' ' ,
V_55 , V_56 , 'q' , F_27 ( 'c' ) , 0 } ;
if ( T_1 -> V_40 != NULL )
F_28 ( T_1 -> V_40 ) ;
F_15 ( T_1 ) ;
T_1 -> V_40 = F_29 ( NULL , NULL , 0 ) ;
if ( T_1 -> V_40 == NULL )
return - 1 ;
T_1 -> V_57 = F_30 ( T_1 -> V_37 , 1 , T_1 -> V_32 ,
V_8 ,
V_3 ) ;
if ( T_1 -> V_57 == NULL )
return - 1 ;
F_24 ( & V_46 ) ;
F_21 ( T_1 , V_44 ) ;
F_20 ( T_1 , V_41 ) ;
F_31 ( T_1 -> V_40 , T_1 -> V_57 ) ;
va_start ( V_48 , V_47 ) ;
F_32 ( V_47 , V_48 ) ;
va_end ( V_48 ) ;
F_25 ( & V_46 ) ;
return 0 ;
}
void F_33 ( struct V_9 * T_1 )
{
F_24 ( & V_46 ) ;
F_28 ( T_1 -> V_40 ) ;
T_1 -> V_40 = NULL ;
F_34 () ;
F_25 ( & V_46 ) ;
}
int F_35 ( struct V_9 * T_1 )
{
int V_30 ;
F_24 ( & V_46 ) ;
F_36 ( T_1 -> V_57 , T_1 -> V_34 , T_1 -> V_58 - 1 ) ;
V_30 = T_1 -> V_59 ( T_1 ) ;
F_2 ( T_1 , V_8 ) ;
F_37 ( T_1 -> V_12 + V_30 , T_1 -> V_13 ,
T_1 -> V_32 - V_30 , T_1 -> V_37 , ' ' ) ;
F_25 ( & V_46 ) ;
return 0 ;
}
int F_38 ( struct V_9 * T_1 )
{
struct V_60 V_61 ;
if ( F_35 ( T_1 ) < 0 )
return - 1 ;
while ( 1 ) {
T_2 V_14 ;
F_39 ( T_1 -> V_40 , & V_61 ) ;
if ( V_61 . V_62 != V_63 )
break;
switch ( V_61 . V_64 . V_39 ) {
case V_50 :
if ( T_1 -> V_34 == T_1 -> V_58 - 1 )
break;
++ T_1 -> V_34 ;
if ( T_1 -> V_34 == T_1 -> V_33 + T_1 -> V_32 ) {
++ T_1 -> V_33 ;
T_1 -> V_38 ( T_1 , + 1 , V_22 ) ;
}
break;
case V_49 :
if ( T_1 -> V_34 == 0 )
break;
-- T_1 -> V_34 ;
if ( T_1 -> V_34 < T_1 -> V_33 ) {
-- T_1 -> V_33 ;
T_1 -> V_38 ( T_1 , - 1 , V_22 ) ;
}
break;
case V_52 :
case ' ' :
if ( T_1 -> V_33 + T_1 -> V_32 > T_1 -> V_58 - 1 )
break;
V_14 = T_1 -> V_32 ;
if ( T_1 -> V_34 + V_14 > T_1 -> V_58 - 1 )
V_14 = T_1 -> V_58 - 1 - T_1 -> V_34 ;
T_1 -> V_34 += V_14 ;
T_1 -> V_33 += V_14 ;
T_1 -> V_38 ( T_1 , + V_14 , V_22 ) ;
break;
case V_51 :
if ( T_1 -> V_33 == 0 )
break;
if ( T_1 -> V_33 < T_1 -> V_32 )
V_14 = T_1 -> V_33 ;
else
V_14 = T_1 -> V_32 ;
T_1 -> V_34 -= V_14 ;
T_1 -> V_33 -= V_14 ;
T_1 -> V_38 ( T_1 , - V_14 , V_22 ) ;
break;
case V_53 :
F_17 ( T_1 ) ;
break;
case V_54 :
V_14 = T_1 -> V_32 - 1 ;
if ( V_14 >= T_1 -> V_58 )
V_14 = T_1 -> V_58 - 1 ;
T_1 -> V_34 = T_1 -> V_58 - 1 ;
T_1 -> V_33 = T_1 -> V_34 - V_14 ;
T_1 -> V_38 ( T_1 , - V_14 , V_24 ) ;
break;
default:
return V_61 . V_64 . V_39 ;
}
if ( F_35 ( T_1 ) < 0 )
return - 1 ;
}
return - 1 ;
}
unsigned int F_40 ( struct V_9 * T_1 )
{
struct V_16 * V_19 ;
struct V_16 * V_17 = T_1 -> V_18 ;
int V_30 = 0 ;
if ( T_1 -> V_23 == NULL || T_1 -> V_23 == T_1 -> V_18 )
T_1 -> V_23 = V_17 -> V_21 ;
V_19 = T_1 -> V_23 ;
F_41 (pos, head) {
F_5 ( T_1 , V_30 , 0 ) ;
T_1 -> V_31 ( T_1 , V_19 , V_30 ) ;
if ( ++ V_30 == T_1 -> V_32 )
break;
}
return V_30 ;
}
void F_42 ( void )
{
struct V_65 * V_66 = & V_67 ;
F_43 ( V_5 , NULL , V_66 -> V_68 , V_66 -> V_69 ) ;
F_43 ( V_7 , NULL , V_66 -> V_70 , V_66 -> V_71 ) ;
F_43 ( V_8 , NULL , V_66 -> V_72 , V_66 -> V_73 ) ;
F_43 ( V_3 , NULL , V_66 -> V_74 , V_66 -> V_75 ) ;
F_43 ( V_76 , NULL , V_66 -> V_77 , V_66 -> V_78 ) ;
}
