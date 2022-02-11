static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
return F_2 ( V_2 , V_4 , V_3 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
return F_4 ( V_2 , V_4 , V_3 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 , T_1 V_4 )
{
return V_4 ;
}
static T_1 F_6 ( struct V_1 * V_2 , T_1 V_4 )
{
return V_4 ^ 0x80000000 ;
}
static T_1 F_7 ( struct V_1 * V_2 , T_1 V_4 )
{
return V_4 & 0x7fffffff ;
}
unsigned int F_8 ( struct V_1 * V_2 , const unsigned int V_5 , T_2 * V_6 )
{
T_3 * V_7 = F_9 () ;
T_1 V_4 ;
unsigned int V_8 , V_9 ;
V_8 = F_10 ( V_5 ) ;
if ( F_11 ( V_5 ) ) {
V_4 = F_12 ( V_8 ) ;
} else if ( V_7 -> V_10 [ V_8 ] == V_11 ) {
V_4 = V_7 -> V_12 [ V_8 ] . V_13 ;
} else {
return 0 ;
}
V_9 = ( V_5 & V_14 ) >> 20 ;
if ( ! F_13 ( V_5 ) ) {
unsigned int V_15 = F_14 ( V_5 ) ;
T_1 V_3 ;
if ( V_7 -> V_10 [ V_15 ] == V_11 &&
V_16 [ V_9 ] ) {
V_3 = V_7 -> V_12 [ V_15 ] . V_13 ;
V_6 -> V_13 = V_16 [ V_9 ] ( V_2 , V_3 , V_4 ) ;
} else {
return 0 ;
}
} else {
if ( V_17 [ V_9 ] ) {
V_6 -> V_13 = V_17 [ V_9 ] ( V_2 , V_4 ) ;
} else {
return 0 ;
}
}
return 1 ;
}
