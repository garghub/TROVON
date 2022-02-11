static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_6 )
{
struct V_7 * V_8 ;
struct V_9 * V_9 ;
unsigned V_10 ;
T_3 V_11 ;
if ( sscanf ( V_5 , L_1 , & V_10 ) != 1 )
return - V_12 ;
if ( V_10 == 0 )
return V_6 ;
V_8 = F_2 ( V_2 ) ;
V_9 = F_3 ( V_8 ) ;
if ( V_9 == NULL )
return - V_13 ;
F_4 ( & V_9 -> V_14 ) ;
V_11 = F_5 ( V_8 -> V_15 ) ;
F_6 ( V_9 , V_11 ) ;
F_7 ( & V_9 -> V_14 ) ;
F_8 ( V_9 ) ;
return V_6 ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
T_1 V_16 ;
struct V_17 * V_17 ;
V_17 = F_10 ( F_2 ( V_2 ) ) ;
if ( V_17 == NULL )
return - V_13 ;
V_16 = F_11 ( V_5 , V_18 , & V_17 -> V_19 ) ;
strcat ( V_5 , L_2 ) ;
F_12 ( V_17 ) ;
return V_16 + 1 ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_6 )
{
int V_16 ;
struct V_7 * V_8 ;
struct V_9 * V_9 ;
struct V_20 V_21 ;
V_16 = sscanf ( V_5 ,
L_3
L_3
L_3
L_4 ,
& V_21 . V_22 [ 0 ] , & V_21 . V_22 [ 1 ] ,
& V_21 . V_22 [ 2 ] , & V_21 . V_22 [ 3 ] ,
& V_21 . V_22 [ 4 ] , & V_21 . V_22 [ 5 ] ,
& V_21 . V_22 [ 6 ] , & V_21 . V_22 [ 7 ] ,
& V_21 . V_22 [ 8 ] , & V_21 . V_22 [ 9 ] ,
& V_21 . V_22 [ 10 ] , & V_21 . V_22 [ 11 ] ,
& V_21 . V_22 [ 12 ] , & V_21 . V_22 [ 13 ] ,
& V_21 . V_22 [ 14 ] , & V_21 . V_22 [ 15 ] ) ;
if ( V_16 != 16 )
return - V_12 ;
V_8 = F_2 ( V_2 ) ;
V_9 = F_3 ( V_8 ) ;
if ( V_9 == NULL )
return - V_13 ;
V_16 = F_14 ( V_9 , V_8 -> V_17 , & V_21 ) ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
F_8 ( V_9 ) ;
return V_16 < 0 ? V_16 : V_6 ;
}
int F_15 ( struct V_9 * V_9 , struct V_7 * V_8 ,
struct V_17 * V_17 )
{
int V_16 = F_16 ( & V_8 -> V_2 . V_23 ,
& V_24 ) ;
struct V_1 * V_2 = & V_8 -> V_2 ;
if ( V_16 < 0 )
F_17 ( V_2 , L_5 ,
V_16 ) ;
return V_16 ;
}
void F_18 ( struct V_17 * V_17 )
{
struct V_7 * V_8 = V_17 -> V_8 ;
if ( V_8 )
F_19 ( & V_8 -> V_2 . V_23 , & V_24 ) ;
}
