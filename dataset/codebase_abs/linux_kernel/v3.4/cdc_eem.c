static void F_1 ( struct V_1 * V_1 )
{
F_2 ( V_1 -> V_2 ) ;
F_3 ( V_1 ) ;
}
static void F_4 ( struct V_3 * V_4 , struct V_5 * V_6 )
{
struct V_1 * V_1 ;
int V_7 ;
V_1 = F_5 ( 0 , V_8 ) ;
if ( ! V_1 )
goto V_9;
F_6 ( V_1 , V_4 -> V_10 , V_4 -> V_11 ,
V_6 -> V_12 , V_6 -> V_13 , F_1 , V_6 ) ;
V_7 = F_7 ( V_1 , V_8 ) ;
if ( V_7 ) {
F_3 ( V_1 ) ;
V_9:
F_2 ( V_6 ) ;
F_8 ( V_4 -> V_14 , L_1 ) ;
return;
}
}
static int F_9 ( struct V_3 * V_4 , struct V_15 * V_16 )
{
int V_7 = 0 ;
V_7 = F_10 ( V_4 , V_16 ) ;
if ( V_7 < 0 ) {
F_11 ( V_16 , NULL ) ;
F_12 ( F_13 ( V_16 ) , V_16 ) ;
return V_7 ;
}
V_4 -> V_14 -> V_17 += V_18 + V_19 ;
V_4 -> V_20 = V_4 -> V_14 -> V_21 + V_4 -> V_14 -> V_17 ;
return 0 ;
}
static struct V_5 * F_14 ( struct V_3 * V_4 , struct V_5 * V_6 ,
T_1 V_22 )
{
struct V_5 * V_23 = NULL ;
T_2 V_13 = V_6 -> V_13 ;
T_3 V_24 = 0 ;
int V_25 = 0 ;
if ( ! ( ( V_13 + V_18 + V_19 ) % V_4 -> V_26 ) )
V_25 += 2 ;
if ( ! F_15 ( V_6 ) ) {
int V_27 = F_16 ( V_6 ) ;
int V_28 = F_17 ( V_6 ) ;
if ( ( V_28 >= V_19 + V_25 ) &&
( V_27 >= V_18 ) )
goto V_29;
if ( ( V_27 + V_28 )
> ( V_18 + V_19 + V_25 ) ) {
V_6 -> V_12 = memmove ( V_6 -> V_30 +
V_18 ,
V_6 -> V_12 ,
V_6 -> V_13 ) ;
F_18 ( V_6 , V_13 ) ;
goto V_29;
}
}
V_23 = F_19 ( V_6 , V_18 , V_19 + V_25 , V_22 ) ;
if ( ! V_23 )
return NULL ;
F_20 ( V_6 ) ;
V_6 = V_23 ;
V_29:
V_24 = F_21 ( ~ 0 , V_6 -> V_12 , V_6 -> V_13 ) ;
V_24 = ~ V_24 ;
F_22 ( V_24 , F_23 ( V_6 , 4 ) ) ;
V_13 = V_6 -> V_13 ;
F_24 ( F_25 ( 14 ) | V_13 , F_26 ( V_6 , 2 ) ) ;
if ( V_25 )
F_24 ( 0 , F_23 ( V_6 , 2 ) ) ;
return V_6 ;
}
static int F_27 ( struct V_3 * V_4 , struct V_5 * V_6 )
{
do {
struct V_5 * V_23 = NULL ;
T_2 V_31 ;
T_2 V_13 = 0 ;
if ( V_6 -> V_13 < V_18 )
return 0 ;
V_31 = F_28 ( V_6 -> V_12 ) ;
F_29 ( V_6 , V_18 ) ;
if ( V_31 & F_25 ( 15 ) ) {
T_2 V_32 ;
if ( V_31 & F_25 ( 14 ) ) {
F_30 ( V_4 -> V_14 , L_2 ,
V_31 ) ;
continue;
}
V_32 = ( V_31 >> 11 ) & 0x7 ;
switch ( V_32 ) {
case 0 :
V_13 = V_31 & 0x7FF ;
if ( V_6 -> V_13 < V_13 )
return 0 ;
V_23 = F_31 ( V_6 , V_8 ) ;
if ( F_32 ( ! V_23 ) )
goto V_33;
F_33 ( V_23 , V_13 ) ;
F_24 ( F_25 ( 15 ) | ( 1 << 11 ) | V_13 ,
F_26 ( V_23 , 2 ) ) ;
F_4 ( V_4 , V_23 ) ;
break;
case 2 :
case 3 :
case 4 :
continue;
case 1 :
case 5 :
default:
F_8 ( V_4 -> V_14 ,
L_3 ,
V_32 ) ;
continue;
}
} else {
T_3 V_24 , V_34 ;
int V_35 ;
if ( V_31 == 0 )
continue;
V_13 = V_31 & 0x3FFF ;
if ( V_6 -> V_13 < V_13 )
return 0 ;
if ( V_13 < ( V_36 + V_19 ) )
goto V_33;
V_35 = ( V_13 == V_6 -> V_13 ) ;
if ( V_35 )
V_23 = V_6 ;
else {
V_23 = F_31 ( V_6 , V_8 ) ;
if ( F_32 ( ! V_23 ) )
return 0 ;
}
if ( V_31 & F_25 ( 14 ) ) {
V_24 = F_34 ( V_23 -> V_12
+ V_13 - V_19 ) ;
V_34 = ~ F_21 ( ~ 0 , V_23 -> V_12 , V_23 -> V_13
- V_19 ) ;
} else {
V_24 = F_35 ( V_23 -> V_12
+ V_13 - V_19 ) ;
V_34 = 0xdeadbeef ;
}
F_33 ( V_23 , V_13 - V_19 ) ;
if ( V_35 )
return V_24 == V_34 ;
if ( F_32 ( V_24 != V_34 ) ) {
V_4 -> V_14 -> V_37 . V_38 ++ ;
F_20 ( V_23 ) ;
} else
F_36 ( V_4 , V_23 ) ;
}
V_33:
F_29 ( V_6 , V_13 ) ;
} while ( V_6 -> V_13 );
return 1 ;
}
