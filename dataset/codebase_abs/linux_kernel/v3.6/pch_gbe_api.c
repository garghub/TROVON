static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 . type = V_4 ;
V_2 -> V_3 . V_5 = V_6 ;
V_2 -> V_3 . V_7 = V_8 ;
}
static T_1 F_2 ( struct V_1 * V_2 )
{
T_1 V_9 ;
V_9 = F_3 ( V_2 ) ;
if ( V_9 ) {
F_4 ( L_1 ) ;
return V_9 ;
}
F_5 ( V_2 ) ;
#ifdef F_6
F_7 ( V_2 ) ;
#endif
return V_9 ;
}
static void F_8 ( struct V_1 * V_2 )
{
V_2 -> V_10 . V_11 = V_12 ;
V_2 -> V_13 = & V_14 ;
}
inline T_1 F_9 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_15 ) {
F_4 ( L_2 ) ;
return - V_16 ;
}
F_8 ( V_2 ) ;
return 0 ;
}
inline void F_10 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_13 -> V_17 )
F_4 ( L_3 ) ;
else
V_2 -> V_13 -> V_17 ( V_2 ) ;
}
inline T_1 F_11 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_13 -> V_18 ) {
F_4 ( L_3 ) ;
return - V_16 ;
}
return V_2 -> V_13 -> V_18 ( V_2 ) ;
}
inline T_1 F_12 ( struct V_1 * V_2 , T_2 V_19 ,
T_3 * V_20 )
{
if ( ! V_2 -> V_13 -> V_21 )
return 0 ;
return V_2 -> V_13 -> V_21 ( V_2 , V_19 , V_20 ) ;
}
inline T_1 F_13 ( struct V_1 * V_2 , T_2 V_19 ,
T_3 V_20 )
{
if ( ! V_2 -> V_13 -> V_22 )
return 0 ;
return V_2 -> V_13 -> V_22 ( V_2 , V_19 , V_20 ) ;
}
inline void F_14 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_13 -> V_23 )
F_4 ( L_3 ) ;
else
V_2 -> V_13 -> V_23 ( V_2 ) ;
}
inline void F_15 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_13 -> V_24 )
F_4 ( L_3 ) ;
else
V_2 -> V_13 -> V_24 ( V_2 ) ;
}
inline T_1 F_16 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_13 -> V_25 ) {
F_4 ( L_3 ) ;
return - V_16 ;
}
return V_2 -> V_13 -> V_25 ( V_2 ) ;
}
inline void F_17 ( struct V_1 * V_2 )
{
if ( V_2 -> V_13 -> V_26 )
V_2 -> V_13 -> V_26 ( V_2 ) ;
}
inline void F_18 ( struct V_1 * V_2 )
{
if ( V_2 -> V_13 -> V_27 )
V_2 -> V_13 -> V_27 ( V_2 ) ;
}
