static void F_1 ( struct V_1 * V_2 )
{
}
static void F_2 ( struct V_1 * V_2 )
{
}
static T_1 F_3 ( int V_3 , void * V_2 )
{
struct V_4 * V_4 = V_2 ;
while ( F_4 ( V_4 -> V_5 . V_6 ) )
F_5 ( F_6 ( V_4 -> V_7 , 0 ) ) ;
return V_8 ;
}
static int F_7 ( struct V_9 * V_10 , unsigned int V_11 ,
T_2 V_12 )
{
struct V_4 * V_4 = V_10 -> V_13 ;
F_8 ( V_11 , V_4 ) ;
F_9 ( V_11 , & V_14 , V_15 ) ;
F_10 ( V_11 , 1 ) ;
F_11 ( V_11 ) ;
return 0 ;
}
int F_12 ( struct V_4 * V_4 )
{
int V_16 ;
unsigned long V_17 ;
struct V_18 * V_5 = & V_4 -> V_5 ;
if ( ! V_4 -> V_3 ) {
F_13 ( V_4 -> V_19 ,
L_1 ) ;
V_4 -> V_20 = 0 ;
return 0 ;
}
V_17 = V_21 | V_22 ;
if ( V_5 -> V_23 )
V_17 = V_5 -> V_23 ;
if ( V_17 & ( V_24 | V_25 ) ) {
if ( F_14 ( V_5 -> V_6 ) != V_4 -> V_3 ) {
F_13 ( V_4 -> V_19 , L_2 ,
V_4 -> V_3 , V_5 -> V_6 ,
F_14 ( V_5 -> V_6 ) ) ;
V_4 -> V_3 = F_14 ( V_5 -> V_6 ) ;
}
V_16 = F_15 ( V_4 -> V_19 , V_5 -> V_6 ,
V_26 , L_3 ) ;
if ( V_16 != 0 ) {
F_16 ( V_4 -> V_19 , L_4 ,
V_16 ) ;
return V_16 ;
}
V_4 -> V_7 = F_17 ( NULL , 1 ,
& V_27 ,
V_4 ) ;
V_16 = F_18 ( V_4 -> V_28 ,
F_6 ( V_4 -> V_7 ,
0 ) ,
V_22 ,
V_4 -> V_20 , & V_29 ,
& V_4 -> V_1 ) ;
if ( V_16 != 0 ) {
F_16 ( V_4 -> V_19 , L_5 ,
V_16 ) ;
return V_16 ;
}
V_16 = F_19 ( V_4 -> V_3 ,
NULL , F_3 ,
V_17 ,
L_6 , V_4 ) ;
} else {
V_16 = F_18 ( V_4 -> V_28 , V_4 -> V_3 ,
V_17 ,
V_4 -> V_20 , & V_29 ,
& V_4 -> V_1 ) ;
}
if ( V_16 != 0 ) {
F_16 ( V_4 -> V_19 , L_7 , V_16 ) ;
return V_16 ;
}
F_20 ( V_4 , V_30 , 0 ) ;
return 0 ;
}
void F_21 ( struct V_4 * V_4 )
{
F_22 ( V_4 -> V_3 , V_4 -> V_1 ) ;
}
