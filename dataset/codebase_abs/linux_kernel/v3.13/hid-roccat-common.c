static inline T_1 F_1 ( T_2 V_1 )
{
return 0x300 | V_1 ;
}
int F_2 ( struct V_2 * V_3 , T_3 V_1 ,
void * V_4 , T_3 V_5 )
{
char * V_6 ;
int V_7 ;
V_6 = F_3 ( V_5 , V_8 ) ;
if ( V_6 == NULL )
return - V_9 ;
V_7 = F_4 ( V_3 , F_5 ( V_3 , 0 ) ,
V_10 ,
V_11 | V_12 | V_13 ,
F_1 ( V_1 ) ,
0 , V_6 , V_5 , V_14 ) ;
memcpy ( V_4 , V_6 , V_5 ) ;
F_6 ( V_6 ) ;
return ( ( V_7 < 0 ) ? V_7 : ( ( V_7 != V_5 ) ? - V_15 : 0 ) ) ;
}
int F_7 ( struct V_2 * V_3 , T_3 V_1 ,
void const * V_4 , T_3 V_5 )
{
char * V_6 ;
int V_7 ;
V_6 = F_8 ( V_4 , V_5 , V_8 ) ;
if ( V_6 == NULL )
return - V_9 ;
V_7 = F_4 ( V_3 , F_9 ( V_3 , 0 ) ,
V_16 ,
V_11 | V_12 | V_17 ,
F_1 ( V_1 ) ,
0 , V_6 , V_5 , V_14 ) ;
F_6 ( V_6 ) ;
return ( ( V_7 < 0 ) ? V_7 : ( ( V_7 != V_5 ) ? - V_15 : 0 ) ) ;
}
static int F_10 ( struct V_2 * V_3 )
{
int V_18 ;
struct V_19 V_20 ;
do {
F_11 ( 50 ) ;
V_18 = F_2 ( V_3 ,
V_21 ,
& V_20 , sizeof( struct V_19 ) ) ;
if ( V_18 )
return V_18 ;
switch ( V_20 . V_22 ) {
case V_23 :
return 0 ;
case V_24 :
F_11 ( 500 ) ;
continue;
case V_25 :
case V_26 :
case V_27 :
return - V_28 ;
default:
F_12 ( & V_3 -> V_29 ,
L_1
L_2 ,
V_20 . V_22 ) ;
return - V_28 ;
}
} while ( 1 );
}
int F_13 ( struct V_2 * V_3 ,
T_3 V_30 , void const * V_6 , T_3 V_5 )
{
int V_18 ;
V_18 = F_7 ( V_3 , V_30 , V_6 , V_5 ) ;
if ( V_18 )
return V_18 ;
F_11 ( 100 ) ;
return F_10 ( V_3 ) ;
}
int F_14 ( struct V_2 * V_3 ,
struct V_31 * V_29 )
{
F_15 ( & V_29 -> V_32 ) ;
return 0 ;
}
T_4 F_16 ( struct V_33 * V_34 , struct V_35 * V_36 ,
char * V_6 , T_5 V_37 , T_6 V_38 ,
T_6 V_39 , T_3 V_30 )
{
struct V_40 * V_29 =
F_17 ( V_36 , struct V_40 , V_36 ) -> V_41 -> V_41 ;
struct V_31 * V_42 = F_18 ( F_19 ( V_29 ) ) ;
struct V_2 * V_3 = F_20 ( F_21 ( V_29 ) ) ;
int V_18 ;
if ( V_37 >= V_39 )
return 0 ;
if ( V_37 != 0 || V_38 != V_39 )
return - V_28 ;
F_22 ( & V_42 -> V_32 ) ;
V_18 = F_2 ( V_3 , V_30 , V_6 , V_39 ) ;
F_23 ( & V_42 -> V_32 ) ;
return V_18 ? V_18 : V_39 ;
}
T_4 F_24 ( struct V_33 * V_34 , struct V_35 * V_36 ,
void const * V_6 , T_5 V_37 , T_6 V_38 ,
T_6 V_39 , T_3 V_30 )
{
struct V_40 * V_29 =
F_17 ( V_36 , struct V_40 , V_36 ) -> V_41 -> V_41 ;
struct V_31 * V_42 = F_18 ( F_19 ( V_29 ) ) ;
struct V_2 * V_3 = F_20 ( F_21 ( V_29 ) ) ;
int V_18 ;
if ( V_37 != 0 || V_38 != V_39 )
return - V_28 ;
F_22 ( & V_42 -> V_32 ) ;
V_18 = F_13 ( V_3 , V_30 , V_6 , V_39 ) ;
F_23 ( & V_42 -> V_32 ) ;
return V_18 ? V_18 : V_39 ;
}
