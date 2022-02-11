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
#ifdef F_11
F_12 ( V_11 , V_16 ) ;
#else
F_13 ( V_11 ) ;
#endif
return 0 ;
}
int F_14 ( struct V_4 * V_4 )
{
int V_17 ;
unsigned long V_18 ;
struct V_19 * V_5 = F_15 ( V_4 -> V_20 ) ;
if ( ! V_4 -> V_3 ) {
F_16 ( V_4 -> V_20 ,
L_1 ) ;
V_4 -> V_21 = 0 ;
return 0 ;
}
V_18 = V_22 | V_23 ;
if ( V_5 -> V_24 )
V_18 = V_5 -> V_24 ;
if ( V_18 & ( V_25 | V_26 ) ) {
if ( F_17 ( V_5 -> V_6 ) != V_4 -> V_3 ) {
F_16 ( V_4 -> V_20 , L_2 ,
V_4 -> V_3 , V_5 -> V_6 ,
F_17 ( V_5 -> V_6 ) ) ;
V_4 -> V_3 = F_17 ( V_5 -> V_6 ) ;
}
V_17 = F_18 ( V_4 -> V_20 , V_5 -> V_6 ,
V_27 , L_3 ) ;
if ( V_17 != 0 ) {
F_19 ( V_4 -> V_20 , L_4 ,
V_17 ) ;
return V_17 ;
}
V_4 -> V_7 = F_20 ( NULL , 1 ,
& V_28 ,
V_4 ) ;
V_17 = F_21 ( V_4 -> V_29 ,
F_6 ( V_4 -> V_7 ,
0 ) ,
V_23 ,
V_4 -> V_21 , & V_30 ,
& V_4 -> V_1 ) ;
if ( V_17 != 0 ) {
F_19 ( V_4 -> V_20 , L_5 ,
V_17 ) ;
return V_17 ;
}
V_17 = F_22 ( V_4 -> V_3 ,
NULL , F_3 ,
V_18 ,
L_6 , V_4 ) ;
} else {
V_17 = F_21 ( V_4 -> V_29 , V_4 -> V_3 ,
V_18 ,
V_4 -> V_21 , & V_30 ,
& V_4 -> V_1 ) ;
}
if ( V_17 != 0 ) {
F_19 ( V_4 -> V_20 , L_7 , V_17 ) ;
return V_17 ;
}
F_23 ( V_4 , V_31 , 0 ) ;
return 0 ;
}
void F_24 ( struct V_4 * V_4 )
{
F_25 ( V_4 -> V_3 , V_4 -> V_1 ) ;
}
