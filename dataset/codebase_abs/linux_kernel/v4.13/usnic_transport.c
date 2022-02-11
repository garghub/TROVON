const char * F_1 ( enum V_1 type )
{
switch ( type ) {
case V_2 :
return L_1 ;
case V_3 :
return L_2 ;
case V_4 :
return L_3 ;
case V_5 :
return L_4 ;
default:
return L_5 ;
}
}
int F_2 ( char * V_6 , int V_7 ,
struct V_8 * V_9 )
{
int V_10 ;
T_1 V_11 ;
T_2 V_12 ;
int V_13 ;
memset ( V_6 , 0 , V_7 ) ;
V_10 = F_3 ( V_9 , & V_13 , & V_11 , & V_12 ) ;
if ( V_10 )
return 0 ;
return F_4 ( V_6 , V_7 , L_6 ,
V_13 , & V_11 , V_12 ) ;
}
T_3 F_5 ( enum V_1 type , T_3 V_14 )
{
if ( type == V_3 ) {
F_6 ( & V_15 ) ;
if ( ! V_14 ) {
V_14 = F_7 ( V_16 ,
V_17 ,
V_18 ,
1 ,
0 ) ;
V_18 = ( V_14 & 4095 ) + 1 ;
} else if ( F_8 ( V_14 , V_16 ) ) {
F_9 ( L_7 ,
F_1 ( type ) ) ;
F_10 ( & V_15 ) ;
goto V_19;
}
F_11 ( V_16 , V_14 , 1 ) ;
F_10 ( & V_15 ) ;
} else {
F_9 ( L_8 ,
F_1 ( type ) ) ;
goto V_19;
}
F_12 ( L_9 , V_14 ,
F_1 ( type ) ) ;
return V_14 ;
V_19:
return 0 ;
}
void F_13 ( enum V_1 type , T_3 V_14 )
{
if ( type == V_3 ) {
F_6 ( & V_15 ) ;
if ( ! V_14 ) {
F_9 ( L_10 ,
F_1 ( type ) ) ;
goto V_20;
}
if ( ! F_8 ( V_14 , V_16 ) ) {
F_9 ( L_11 ,
V_14 ,
F_1 ( type ) ) ;
goto V_20;
}
F_14 ( V_16 , V_14 , 1 ) ;
F_12 ( L_12 , V_14 ,
F_1 ( type ) ) ;
V_20:
F_10 ( & V_15 ) ;
} else {
F_9 ( L_13 , V_14 , type ) ;
}
}
struct V_8 * F_15 ( int V_21 )
{
struct V_8 * V_9 ;
int V_10 ;
char V_6 [ 25 ] ;
V_9 = F_16 ( V_21 , & V_10 ) ;
if ( ! V_9 ) {
F_9 ( L_14 ,
V_21 , V_10 ) ;
return F_17 ( - V_22 ) ;
}
F_2 ( V_6 , sizeof( V_6 ) , V_9 ) ;
F_12 ( L_15 , V_6 ) ;
return V_9 ;
}
void F_18 ( struct V_8 * V_9 )
{
char V_6 [ 100 ] ;
F_2 ( V_6 , sizeof( V_6 ) , V_9 ) ;
F_12 ( L_16 , V_6 ) ;
F_19 ( V_9 ) ;
}
int F_3 ( struct V_8 * V_9 , int * V_13 ,
T_1 * V_11 , T_2 * V_12 )
{
int V_23 ;
int V_10 ;
struct V_24 V_25 ;
V_10 = V_9 -> V_26 -> V_27 ( V_9 ,
(struct V_28 * ) & V_25 ,
& V_23 , 0 ) ;
if ( V_10 )
return V_10 ;
if ( V_25 . V_29 != V_30 )
return - V_31 ;
if ( V_13 )
* V_13 = V_9 -> V_32 -> V_33 ;
if ( V_12 )
* V_12 = F_20 ( ( (struct V_24 * ) & V_25 ) -> V_34 ) ;
if ( V_11 )
* V_11 = F_21 ( ( (struct V_24 * )
& V_25 ) -> V_35 . V_36 ) ;
return 0 ;
}
int F_22 ( void )
{
V_16 = F_23 ( V_17 , V_37 ) ;
if ( ! V_16 ) {
F_9 ( L_17 ) ;
return - V_38 ;
}
F_11 ( V_16 , 0 , 1 ) ;
return 0 ;
}
void F_24 ( void )
{
F_25 ( V_16 ) ;
}
