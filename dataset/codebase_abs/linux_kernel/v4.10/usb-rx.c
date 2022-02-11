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
( long ) F_22 ( V_38 ) ) ;
goto V_24;
}
case - V_41 :
F_9 ( V_3 , L_16 , V_14 ) ;
V_14 = 0 ;
break;
default:
if ( F_16 ( & V_1 -> V_28 ,
V_29 , V_30 ) )
goto V_42;
F_9 ( V_3 , L_17 , V_14 ) ;
goto V_24;
}
V_39:
if ( V_17 )
F_23 ( V_1 -> V_4 ) ;
F_24 ( 4 , V_3 , L_18 , V_1 , V_13 ) ;
return V_13 ;
V_42:
F_9 ( V_3 , L_19
L_20 ) ;
V_31:
F_25 ( V_1 -> V_4 ) ;
V_13 = F_26 ( V_14 ) ;
goto V_39;
}
static
int F_27 ( void * V_43 )
{
int V_14 = 0 ;
struct V_1 * V_1 = V_43 ;
struct V_44 * V_44 = & V_1 -> V_44 ;
struct V_2 * V_3 = & V_1 -> V_4 -> V_3 ;
struct V_45 * V_46 = V_44 -> V_47 . V_46 ;
T_1 V_48 ;
int V_5 ;
struct V_12 * V_13 ;
unsigned long V_49 ;
F_6 ( 4 , V_3 , L_6 , V_1 ) ;
F_28 ( & V_44 -> V_50 , V_49 ) ;
F_29 ( V_1 -> V_51 != NULL ) ;
V_1 -> V_51 = V_52 ;
F_30 ( & V_44 -> V_50 , V_49 ) ;
while ( 1 ) {
F_2 ( 2 , V_3 , L_21 ) ;
V_48 = 0 ;
F_31 (
V_1 -> V_53 ,
( F_32 ()
|| ( V_48 = F_7 ( & V_1 -> V_54 ) ) )
) ;
if ( F_32 () )
break;
if ( V_48 == 0 )
continue;
V_5 = V_1 -> V_5 ;
F_2 ( 2 , V_3 , L_22 , V_5 ) ;
V_13 = F_33 ( V_46 , V_5 , V_40 ) ;
if ( V_13 == NULL ) {
F_9 ( V_3 , L_23 ,
V_5 ) ;
F_18 ( 50 ) ;
continue;
}
V_13 = F_5 ( V_1 , V_13 ) ;
V_14 = F_34 ( V_13 ) ;
if ( F_35 ( V_13 ) )
goto V_39;
F_36 ( & V_1 -> V_54 ) ;
if ( V_13 == NULL || V_13 -> V_26 == 0 ) {
F_21 ( V_13 ) ;
continue;
}
V_1 -> V_7 ++ ;
V_1 -> V_10 += V_13 -> V_26 ;
V_14 = F_37 ( V_44 , V_13 ) ;
if ( V_14 == - V_55
&& F_16 ( & V_1 -> V_28 ,
V_29 , V_30 ) ) {
goto V_42;
}
F_3 ( V_1 ) ;
}
V_14 = 0 ;
V_39:
F_28 ( & V_44 -> V_50 , V_49 ) ;
V_1 -> V_51 = NULL ;
F_30 ( & V_44 -> V_50 , V_49 ) ;
F_24 ( 4 , V_3 , L_24 , V_1 , V_14 ) ;
return V_14 ;
V_42:
F_9 ( V_3 , L_25
L_20 ) ;
F_25 ( V_1 -> V_4 ) ;
goto V_39;
}
void F_38 ( struct V_1 * V_1 )
{
struct V_44 * V_44 = & V_1 -> V_44 ;
struct V_2 * V_3 = & V_1 -> V_4 -> V_3 ;
F_6 ( 3 , V_3 , L_6 , V_44 ) ;
F_39 ( & V_1 -> V_54 ) ;
F_40 ( & V_1 -> V_53 ) ;
F_24 ( 3 , V_3 , L_26 , V_44 ) ;
}
int F_41 ( struct V_1 * V_1 )
{
int V_14 = 0 ;
struct V_44 * V_44 = & V_1 -> V_44 ;
struct V_2 * V_3 = & V_1 -> V_4 -> V_3 ;
struct V_47 * V_47 = & V_44 -> V_47 ;
struct V_56 * V_57 ;
V_57 = F_42 ( F_27 , V_1 , L_27 ,
V_47 -> V_58 ) ;
if ( F_35 ( V_57 ) ) {
V_14 = F_34 ( V_57 ) ;
F_9 ( V_3 , L_28 , V_14 ) ;
}
return V_14 ;
}
void F_43 ( struct V_1 * V_1 )
{
unsigned long V_49 ;
struct V_44 * V_44 = & V_1 -> V_44 ;
struct V_2 * V_3 = F_44 ( V_44 ) ;
struct V_56 * V_57 ;
F_28 ( & V_44 -> V_50 , V_49 ) ;
V_57 = V_1 -> V_51 ;
V_1 -> V_51 = NULL ;
F_30 ( & V_44 -> V_50 , V_49 ) ;
if ( V_57 )
F_45 ( V_57 ) ;
else
F_2 ( 1 , V_3 , L_29 ) ;
}
