static
T_1 F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = & V_1 -> V_4 -> V_3 ;
T_1 V_5 ;
const T_1 V_6 = 512 ;
V_5 = 2 * V_1 -> V_5 ;
if ( V_5 % V_6 == 0 ) {
V_5 -= 8 ;
F_2 ( 1 , V_3 ,
L_1
L_2 ,
V_5 , V_1 -> V_5 ) ;
} else
F_2 ( 1 , V_3 ,
L_3 ,
V_5 , V_1 -> V_5 ) ;
return V_5 ;
}
static
void F_3 ( struct V_1 * V_1 )
{
const T_1 V_6 = 512 ;
struct V_2 * V_3 = & V_1 -> V_4 -> V_3 ;
if ( F_4 ( V_1 -> V_7 >= 100
&& V_1 -> V_8 ) ) {
T_1 V_9 =
V_1 -> V_10 / V_1 -> V_7 ;
T_1 V_11 = V_1 -> V_5 / 2 ;
if ( V_9 < V_11 ) {
if ( V_11 % V_6 == 0 ) {
V_11 -= 8 ;
F_2 ( 1 , V_3 ,
L_4
L_5 ,
V_11 , V_1 -> V_5 ) ;
} else
F_2 ( 1 , V_3 ,
L_4
L_2 ,
V_11 , V_1 -> V_5 ) ;
V_1 -> V_5 = V_11 ;
V_1 -> V_7 = 0 ;
V_1 -> V_10 = V_1 -> V_5 ;
}
}
}
static
struct V_12 * F_5 ( struct V_1 * V_1 , struct V_12 * V_13 )
{
int V_14 = 0 ;
struct V_2 * V_3 = & V_1 -> V_4 -> V_3 ;
int V_15 , V_16 , V_5 , V_17 ;
struct V_18 * V_19 ;
const T_1 V_6 = 512 ;
F_6 ( 4 , V_3 , L_6 , V_1 ) ;
V_17 = F_7 ( & V_1 -> V_17 ) ;
V_14 = V_17 ?
F_8 ( V_1 -> V_4 ) : 0 ;
if ( V_14 < 0 ) {
F_9 ( V_3 , L_7 , V_14 ) ;
V_17 = 0 ;
}
V_19 = F_10 ( V_1 -> V_4 , V_1 -> V_20 . V_21 ) ;
V_15 = F_11 ( V_1 -> V_22 , V_19 -> V_23 ) ;
V_24:
V_5 = F_12 ( V_13 ) - V_13 -> V_25 - V_13 -> V_26 ;
if ( F_4 ( V_5 % V_6 == 0 ) ) {
V_5 -= 8 ;
F_2 ( 1 , V_3 , L_8 , V_5 ) ;
}
V_14 = F_13 (
V_1 -> V_22 , V_15 , V_13 -> V_25 + V_13 -> V_26 ,
V_5 , & V_16 , 200 ) ;
F_14 ( V_1 -> V_22 ) ;
switch ( V_14 ) {
case 0 :
if ( V_16 == 0 )
goto V_24;
F_15 ( V_13 , V_16 ) ;
break;
case - V_27 :
if ( F_16 ( & V_1 -> V_28 ,
10 * V_29 , V_30 ) ) {
F_9 ( V_3 , L_9
L_10 ) ;
goto V_31;
}
F_17 ( V_1 -> V_22 , V_15 ) ;
F_18 ( 10 ) ;
goto V_24;
case - V_32 :
case - V_33 :
case - V_34 :
case - V_35 :
case - V_36 :
break;
case - V_37 : {
struct V_12 * V_38 ;
V_5 = F_1 ( V_1 ) ;
if ( V_5 <= ( 1 << 16 ) )
V_1 -> V_5 = V_5 ;
else if ( F_19 () ) {
F_9 ( V_3 , L_11 , V_5 ) ;
V_14 = - V_32 ;
goto V_39;
}
F_15 ( V_13 , V_16 ) ;
V_38 = F_20 ( V_13 , 0 , V_5 - V_13 -> V_26 ,
V_40 ) ;
if ( V_38 == NULL ) {
if ( F_19 () )
F_9 ( V_3 , L_12
L_13 , V_5 ) ;
F_21 ( V_13 ) ;
V_13 = NULL ;
goto V_39;
}
F_21 ( V_13 ) ;
V_13 = V_38 ;
V_1 -> V_7 = 0 ;
V_1 -> V_10 = V_1 -> V_5 ;
F_2 ( 1 , V_3 , L_14
L_15 ,
V_5 , V_16 , V_13 -> V_26 ,
( long ) ( F_12 ( V_38 ) - V_38 -> V_41 ) ) ;
goto V_24;
}
case - V_42 :
F_9 ( V_3 , L_16 , V_14 ) ;
V_14 = 0 ;
break;
default:
if ( F_16 ( & V_1 -> V_28 ,
V_29 , V_30 ) )
goto V_43;
F_9 ( V_3 , L_17 , V_14 ) ;
goto V_24;
}
V_39:
if ( V_17 )
F_22 ( V_1 -> V_4 ) ;
F_23 ( 4 , V_3 , L_18 , V_1 , V_13 ) ;
return V_13 ;
V_43:
F_9 ( V_3 , L_19
L_20 ) ;
V_31:
F_24 ( V_1 -> V_4 ) ;
V_13 = F_25 ( V_14 ) ;
goto V_39;
}
static
int F_26 ( void * V_44 )
{
int V_14 = 0 ;
struct V_1 * V_1 = V_44 ;
struct V_45 * V_45 = & V_1 -> V_45 ;
struct V_2 * V_3 = & V_1 -> V_4 -> V_3 ;
struct V_46 * V_47 = V_45 -> V_48 . V_47 ;
T_1 V_49 ;
int V_5 ;
struct V_12 * V_13 ;
unsigned long V_50 ;
F_6 ( 4 , V_3 , L_6 , V_1 ) ;
F_27 ( & V_45 -> V_51 , V_50 ) ;
F_28 ( V_1 -> V_52 != NULL ) ;
V_1 -> V_52 = V_53 ;
F_29 ( & V_45 -> V_51 , V_50 ) ;
while ( 1 ) {
F_2 ( 2 , V_3 , L_21 ) ;
V_49 = 0 ;
F_30 (
V_1 -> V_54 ,
( F_31 ()
|| ( V_49 = F_7 ( & V_1 -> V_55 ) ) )
) ;
if ( F_31 () )
break;
if ( V_49 == 0 )
continue;
V_5 = V_1 -> V_5 ;
F_2 ( 2 , V_3 , L_22 , V_5 ) ;
V_13 = F_32 ( V_47 , V_5 , V_40 ) ;
if ( V_13 == NULL ) {
F_9 ( V_3 , L_23 ,
V_5 ) ;
F_18 ( 50 ) ;
continue;
}
V_13 = F_5 ( V_1 , V_13 ) ;
V_14 = F_33 ( V_13 ) ;
if ( F_34 ( V_13 ) )
goto V_39;
F_35 ( & V_1 -> V_55 ) ;
if ( V_13 == NULL || V_13 -> V_26 == 0 ) {
F_21 ( V_13 ) ;
continue;
}
V_1 -> V_7 ++ ;
V_1 -> V_10 += V_13 -> V_26 ;
V_14 = F_36 ( V_45 , V_13 ) ;
if ( V_14 == - V_56
&& F_16 ( & V_1 -> V_28 ,
V_29 , V_30 ) ) {
goto V_43;
}
F_3 ( V_1 ) ;
}
V_14 = 0 ;
V_39:
F_27 ( & V_45 -> V_51 , V_50 ) ;
V_1 -> V_52 = NULL ;
F_29 ( & V_45 -> V_51 , V_50 ) ;
F_23 ( 4 , V_3 , L_24 , V_1 , V_14 ) ;
return V_14 ;
V_43:
F_9 ( V_3 , L_25
L_20 ) ;
F_24 ( V_1 -> V_4 ) ;
goto V_39;
}
void F_37 ( struct V_1 * V_1 )
{
struct V_45 * V_45 = & V_1 -> V_45 ;
struct V_2 * V_3 = & V_1 -> V_4 -> V_3 ;
F_6 ( 3 , V_3 , L_6 , V_45 ) ;
F_38 ( & V_1 -> V_55 ) ;
F_39 ( & V_1 -> V_54 ) ;
F_23 ( 3 , V_3 , L_26 , V_45 ) ;
}
int F_40 ( struct V_1 * V_1 )
{
int V_14 = 0 ;
struct V_45 * V_45 = & V_1 -> V_45 ;
struct V_2 * V_3 = & V_1 -> V_4 -> V_3 ;
struct V_48 * V_48 = & V_45 -> V_48 ;
struct V_57 * V_58 ;
V_58 = F_41 ( F_26 , V_1 , L_27 ,
V_48 -> V_59 ) ;
if ( F_34 ( V_58 ) ) {
V_14 = F_33 ( V_58 ) ;
F_9 ( V_3 , L_28 , V_14 ) ;
}
return V_14 ;
}
void F_42 ( struct V_1 * V_1 )
{
unsigned long V_50 ;
struct V_45 * V_45 = & V_1 -> V_45 ;
struct V_2 * V_3 = F_43 ( V_45 ) ;
struct V_57 * V_58 ;
F_27 ( & V_45 -> V_51 , V_50 ) ;
V_58 = V_1 -> V_52 ;
V_1 -> V_52 = NULL ;
F_29 ( & V_45 -> V_51 , V_50 ) ;
if ( V_58 )
F_44 ( V_58 ) ;
else
F_2 ( 1 , V_3 , L_29 ) ;
}
