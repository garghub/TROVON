const struct V_1 * F_1 ( unsigned int V_2 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; ++ V_3 ) {
const struct V_1 * V_5 = & V_4 [ V_3 ] ;
if ( V_5 -> V_2 == V_2 )
return V_5 ;
}
return F_3 ( - V_6 ) ;
}
const struct V_1 * F_4 ( T_1 V_7 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; ++ V_3 ) {
const struct V_1 * V_5 = & V_4 [ V_3 ] ;
if ( V_5 -> V_7 == V_7 )
return V_5 ;
}
return F_3 ( - V_6 ) ;
}
const struct V_1 * F_5 ( struct V_8 * V_9 )
{
const char * V_10 = L_1 ;
unsigned int V_11 ;
unsigned int V_3 ;
T_1 V_12 ;
int V_13 ;
V_13 = F_6 ( V_9 , L_2 , & V_11 ) ;
if ( V_13 < 0 )
return F_3 ( V_13 ) ;
V_13 = F_6 ( V_9 , L_3 , & V_12 ) ;
if ( V_13 < 0 )
return F_3 ( V_13 ) ;
if ( V_11 == V_14 )
F_7 ( V_9 , L_4 , & V_10 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; ++ V_3 ) {
const struct V_1 * V_5 = & V_4 [ V_3 ] ;
if ( V_5 -> V_11 != V_11 || V_5 -> V_12 != V_12 )
continue;
if ( V_11 == V_14 &&
strcmp ( V_10 , V_5 -> V_10 ) )
continue;
return V_5 ;
}
return F_3 ( - V_6 ) ;
}
void F_8 ( struct V_15 * V_5 ,
const struct V_16 * V_17 )
{
V_5 -> V_12 = F_9 (unsigned int, fmt->format.width,
XVIP_MIN_WIDTH, XVIP_MAX_WIDTH) ;
V_5 -> V_18 = F_9 (unsigned int, fmt->format.height,
XVIP_MIN_HEIGHT, XVIP_MAX_HEIGHT) ;
}
void F_10 ( struct V_19 * V_20 , T_1 V_21 , T_1 V_22 , bool V_23 )
{
T_1 V_24 ;
V_24 = F_11 ( V_20 , V_21 ) ;
V_24 = V_23 ? V_24 | V_22 : V_24 & ~ V_22 ;
F_12 ( V_20 , V_21 , V_24 ) ;
}
void F_13 ( struct V_19 * V_20 , T_1 V_21 , T_1 V_25 , T_1 V_23 )
{
T_1 V_24 ;
V_24 = F_11 ( V_20 , V_21 ) ;
V_24 &= ~ V_25 ;
V_24 |= V_23 ;
F_12 ( V_20 , V_21 , V_24 ) ;
}
int F_14 ( struct V_19 * V_20 )
{
struct V_26 * V_27 = F_15 ( V_20 -> V_28 ) ;
struct V_29 * V_30 ;
V_30 = F_16 ( V_27 , V_31 , 0 ) ;
V_20 -> V_32 = F_17 ( V_20 -> V_28 , V_30 ) ;
if ( F_18 ( V_20 -> V_32 ) )
return F_19 ( V_20 -> V_32 ) ;
V_20 -> V_33 = F_20 ( V_20 -> V_28 , NULL ) ;
if ( F_18 ( V_20 -> V_33 ) )
return F_19 ( V_20 -> V_33 ) ;
F_21 ( V_20 -> V_33 ) ;
return 0 ;
}
void F_22 ( struct V_19 * V_20 )
{
F_23 ( V_20 -> V_33 ) ;
}
int F_24 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
struct V_38 * V_2 )
{
struct V_15 * V_5 ;
if ( V_2 -> V_39 == V_40 )
return - V_6 ;
if ( V_2 -> V_41 )
return - V_6 ;
V_5 = F_25 ( V_35 , V_37 , V_2 -> V_42 ) ;
V_2 -> V_2 = V_5 -> V_2 ;
return 0 ;
}
int F_26 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
struct V_43 * V_44 )
{
struct V_15 * V_5 ;
if ( V_44 -> V_39 == V_40 )
return - V_6 ;
V_5 = F_25 ( V_35 , V_37 , V_44 -> V_42 ) ;
if ( V_44 -> V_41 || V_44 -> V_2 != V_5 -> V_2 )
return - V_6 ;
if ( V_44 -> V_42 == V_45 ) {
V_44 -> V_46 = V_47 ;
V_44 -> V_48 = V_49 ;
V_44 -> V_50 = V_51 ;
V_44 -> V_52 = V_53 ;
} else {
V_44 -> V_46 = V_5 -> V_12 ;
V_44 -> V_48 = V_5 -> V_12 ;
V_44 -> V_50 = V_5 -> V_18 ;
V_44 -> V_52 = V_5 -> V_18 ;
}
return 0 ;
}
