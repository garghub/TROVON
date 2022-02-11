static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 , int * V_5 ,
int * V_6 , long V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
unsigned long V_10 ;
int V_11 ;
switch ( V_7 ) {
case V_12 :
F_3 ( & V_9 -> V_13 ) ;
if ( V_9 -> V_14 != V_4 -> V_4 ) {
V_9 -> V_14 = V_4 -> V_4 ;
F_4 () ;
F_5 ( 0xAA , V_9 -> V_15 + V_16 ) ;
F_5 ( V_4 -> V_17 ,
V_9 -> V_15 + V_18 ) ;
F_6 () ;
F_7 ( 2000 , 2000 ) ;
}
F_8 ( V_9 -> V_15 + V_19 ) ;
F_7 ( F_9 ( 1000000 , 925 ) ,
F_9 ( 1000000 , 925 ) ) ;
V_11 = V_20 ;
V_10 = V_21 + F_10 ( 1 ) + 1 ;
while ( 1 ) {
T_1 V_22 ;
V_22 = F_8 ( V_9 -> V_15 + V_19 ) ;
if ( V_22 & V_23 ) {
* V_5 = F_11 ( V_22 , 15 ) ;
break;
}
if ( F_12 ( V_21 , V_10 ) ) {
F_13 ( & V_2 -> V_24 , L_1 ) ;
V_11 = - V_25 ;
break;
}
F_14 () ;
}
F_15 ( & V_9 -> V_13 ) ;
return V_11 ;
case V_26 :
* V_5 = 25000 ;
return V_20 ;
case V_27 :
* V_5 = ( 1ULL << 32 ) * 3300 / 50000 ;
* V_6 = 32 ;
return V_28 ;
}
return - V_29 ;
}
static int F_16 ( struct V_30 * V_31 )
{
int V_11 ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
struct V_32 * V_33 ;
struct V_34 * V_35 ;
V_2 = F_17 ( & V_31 -> V_24 , sizeof( * V_9 ) ) ;
if ( ! V_2 )
return - V_36 ;
V_9 = F_2 ( V_2 ) ;
V_35 = F_18 ( V_31 , V_37 , 0 ) ;
if ( ! V_35 ) {
F_13 ( & V_31 -> V_24 , L_2 ) ;
return - V_38 ;
}
V_9 -> V_15 = F_19 ( & V_31 -> V_24 , V_35 ) ;
if ( F_20 ( V_9 -> V_15 ) ) {
F_13 ( & V_31 -> V_24 , L_3 ) ;
return F_21 ( V_9 -> V_15 ) ;
}
V_2 -> V_24 . V_39 = & V_31 -> V_24 ;
V_2 -> V_40 = F_22 ( & V_31 -> V_24 ) ;
V_2 -> V_41 = V_42 ;
V_2 -> V_43 = & V_44 ;
V_2 -> V_45 = F_23 ( V_46 ) ;
V_2 -> V_47 = V_46 ;
V_9 -> V_14 = - 1 ;
F_24 ( & V_9 -> V_13 ) ;
F_25 ( V_31 , V_2 ) ;
V_9 -> V_32 = F_26 ( & V_31 -> V_24 , NULL ) ;
if ( F_20 ( V_9 -> V_32 ) ) {
F_13 ( & V_31 -> V_24 , L_4 ) ;
return F_21 ( V_9 -> V_32 ) ;
}
V_33 = F_27 ( V_9 -> V_32 ) ;
if ( ! V_33 ) {
F_28 ( & V_31 -> V_24 , L_5 ) ;
} else {
V_11 = F_29 ( V_9 -> V_32 , F_30 ( V_33 ) / 16 ) ;
if ( V_11 )
F_28 ( & V_31 -> V_24 , L_6 ) ;
}
V_11 = F_31 ( V_9 -> V_32 ) ;
if ( V_11 ) {
F_13 ( & V_31 -> V_24 , L_7 ) ;
return V_11 ;
}
V_11 = F_32 ( V_2 ) ;
if ( V_11 )
F_33 ( V_9 -> V_32 ) ;
return V_11 ;
}
static int F_34 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_35 ( V_31 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_36 ( V_2 ) ;
F_33 ( V_9 -> V_32 ) ;
return 0 ;
}
