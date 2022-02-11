static
int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 ,
T_1 V_4 )
{
int V_5 = 0 ;
struct V_6 * V_6 = & V_1 -> V_6 ;
struct V_7 * V_8 = & V_1 -> V_9 -> V_8 ;
int V_10 , V_11 , V_12 ;
struct V_13 * V_14 ;
F_2 ( 4 , V_8 , L_1 , V_1 ) ;
V_12 = F_3 ( & V_1 -> V_12 ) ;
V_5 = V_12 ?
F_4 ( V_1 -> V_9 ) : 0 ;
if ( V_5 < 0 ) {
F_5 ( V_8 , L_2 , V_5 ) ;
V_12 = 0 ;
}
V_14 = F_6 ( V_1 -> V_9 , V_1 -> V_15 . V_16 ) ;
V_10 = F_7 ( V_1 -> V_17 , V_14 -> V_18 ) ;
V_19:
V_5 = F_8 ( V_1 -> V_17 , V_10 ,
V_3 , V_4 , & V_11 , 200 ) ;
F_9 ( V_1 -> V_17 ) ;
switch ( V_5 ) {
case 0 :
if ( V_11 != V_4 ) {
F_5 ( V_8 , L_3
L_4 , V_11 , V_4 ) ;
V_5 = - V_20 ;
}
break;
case - V_21 :
if ( F_10 ( & V_1 -> V_22 ,
10 * V_23 , V_24 ) ) {
F_5 ( V_8 , L_5
L_6 ) ;
F_11 ( V_1 -> V_9 ) ;
} else {
F_12 ( V_1 -> V_17 , V_10 ) ;
F_13 ( 10 ) ;
goto V_19;
}
case - V_25 :
case - V_26 :
case - V_27 :
case - V_28 :
case - V_29 :
V_5 = - V_28 ;
break;
default:
if ( F_10 ( & V_1 -> V_22 ,
V_23 , V_24 ) ) {
F_5 ( V_8 , L_7
L_8 ) ;
F_11 ( V_1 -> V_9 ) ;
} else {
F_5 ( V_8 , L_9
L_10 ,
( void * ) V_3 - V_6 -> V_30 ,
V_4 , V_11 , V_5 ) ;
goto V_19;
}
}
if ( V_12 )
F_14 ( V_1 -> V_9 ) ;
F_15 ( 4 , V_8 , L_11 , V_1 ) ;
return V_5 ;
}
static
int F_16 ( void * V_31 )
{
struct V_1 * V_1 = V_31 ;
struct V_6 * V_6 = & V_1 -> V_6 ;
struct V_7 * V_8 = & V_1 -> V_9 -> V_8 ;
struct V_2 * V_3 ;
T_1 V_4 ;
unsigned long V_32 ;
F_2 ( 4 , V_8 , L_1 , V_1 ) ;
F_17 ( & V_6 -> V_33 , V_32 ) ;
F_18 ( V_1 -> V_34 != NULL ) ;
V_1 -> V_34 = V_35 ;
F_19 ( & V_6 -> V_33 , V_32 ) ;
while ( 1 ) {
F_20 ( 2 , V_8 , L_12 ) ;
V_3 = NULL ;
F_21 (
V_1 -> V_36 ,
( F_22 ()
|| ( V_3 = F_23 ( V_6 , & V_4 ) ) )
) ;
if ( F_22 () )
break;
F_24 ( V_3 == NULL ) ;
F_20 ( 2 , V_8 , L_13 , V_4 ) ;
F_25 ( 5 , V_8 , V_3 , V_4 ) ;
F_1 ( V_1 , V_3 , V_4 ) ;
F_26 ( V_6 ) ;
}
F_17 ( & V_6 -> V_33 , V_32 ) ;
V_1 -> V_34 = NULL ;
F_19 ( & V_6 -> V_33 , V_32 ) ;
F_15 ( 4 , V_8 , L_1 , V_1 ) ;
return 0 ;
}
void F_27 ( struct V_6 * V_6 )
{
struct V_1 * V_1 = F_28 ( V_6 , struct V_1 , V_6 ) ;
struct V_7 * V_8 = & V_1 -> V_9 -> V_8 ;
F_2 ( 3 , V_8 , L_14 , V_6 ) ;
F_29 ( & V_1 -> V_36 ) ;
F_15 ( 3 , V_8 , L_14 , V_6 ) ;
}
int F_30 ( struct V_1 * V_1 )
{
int V_5 = 0 ;
struct V_6 * V_6 = & V_1 -> V_6 ;
struct V_7 * V_8 = & V_1 -> V_9 -> V_8 ;
struct V_37 * V_37 = & V_6 -> V_37 ;
struct V_38 * V_39 ;
V_39 = F_31 ( F_16 , V_1 , L_15 ,
V_37 -> V_40 ) ;
if ( F_32 ( V_39 ) ) {
V_5 = F_33 ( V_39 ) ;
F_5 ( V_8 , L_16 , V_5 ) ;
}
return V_5 ;
}
void F_34 ( struct V_1 * V_1 )
{
unsigned long V_32 ;
struct V_6 * V_6 = & V_1 -> V_6 ;
struct V_7 * V_8 = F_35 ( V_6 ) ;
struct V_38 * V_39 ;
F_17 ( & V_6 -> V_33 , V_32 ) ;
V_39 = V_1 -> V_34 ;
V_1 -> V_34 = NULL ;
F_19 ( & V_6 -> V_33 , V_32 ) ;
if ( V_39 )
F_36 ( V_39 ) ;
else
F_20 ( 1 , V_8 , L_17 ) ;
}
