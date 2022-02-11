static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_6 = NULL ;
int V_7 = V_5 -> V_8 [ 0 ] ;
int V_9 = V_5 -> V_8 [ 1 ] ;
F_2 (pcidev) {
if ( V_6 -> V_10 != V_11 ||
V_6 -> V_12 != V_13 )
continue;
if ( V_7 || V_9 ) {
if ( V_6 -> V_7 -> V_14 != V_7 ||
F_3 ( V_6 -> V_15 ) != V_9 )
continue;
}
return V_6 ;
}
F_4 ( V_16
L_1 ,
V_3 -> V_17 , V_7 , V_9 ) ;
return NULL ;
}
static int F_5 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_6 ;
struct V_18 * V_19 ;
int V_20 ;
F_4 ( V_21 L_2 , V_3 -> V_17 ) ;
V_3 -> V_22 = L_3 ;
V_20 = F_6 ( V_3 , 4 ) ;
if ( V_20 )
return V_20 ;
V_6 = F_1 ( V_3 , V_5 ) ;
if ( ! V_6 )
return - V_23 ;
F_7 ( V_3 , & V_6 -> V_3 ) ;
if ( F_8 ( V_6 , L_4 ) < 0 ) {
F_4 ( V_16
L_5 ,
V_3 -> V_17 ) ;
return - V_23 ;
}
V_3 -> V_24 = F_9 ( V_6 , 2 ) ;
F_4 ( V_21 L_6 , V_3 -> V_24 ) ;
V_19 = V_3 -> V_25 + 0 ;
F_10 ( V_3 , V_19 , NULL , ( unsigned long ) ( V_3 -> V_24 ) ) ;
V_19 = V_3 -> V_25 + 1 ;
V_20 = F_10 ( V_3 , V_19 , NULL ,
( unsigned long ) ( V_3 -> V_24 + V_26 ) ) ;
if ( V_20 < 0 )
return V_20 ;
V_19 = V_3 -> V_25 + 2 ;
V_20 = F_10 ( V_3 , V_19 , NULL ,
( unsigned long ) ( V_3 -> V_24 + V_27 ) ) ;
if ( V_20 < 0 )
return V_20 ;
V_19 = V_3 -> V_25 + 3 ;
V_20 = F_10 ( V_3 , V_19 , NULL ,
( unsigned long ) ( V_3 -> V_24 + V_28 ) ) ;
if ( V_20 < 0 )
return V_20 ;
F_4 ( V_29 L_7 , V_3 -> V_17 ) ;
return 0 ;
}
static void F_11 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_12 ( V_3 ) ;
if ( V_6 ) {
if ( V_3 -> V_24 )
F_13 ( V_6 ) ;
F_14 ( V_6 ) ;
}
if ( V_3 -> V_25 ) {
F_15 ( V_3 , V_3 -> V_25 + 0 ) ;
F_15 ( V_3 , V_3 -> V_25 + 1 ) ;
F_15 ( V_3 , V_3 -> V_25 + 2 ) ;
F_15 ( V_3 , V_3 -> V_25 + 3 ) ;
}
}
static int T_1 F_16 ( struct V_1 * V_3 ,
const struct V_30 * V_31 )
{
return F_17 ( V_3 , & V_32 ) ;
}
static void T_2 F_18 ( struct V_1 * V_3 )
{
F_19 ( V_3 ) ;
}
