static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
unsigned short V_7 ;
unsigned int V_8 ;
if ( ! F_2 ( V_2 , V_9 ) )
return 0 ;
V_7 = V_2 -> V_10 [ 2 ] ;
V_8 = ( ( V_2 -> V_10 [ 0 ] << 8 ) & 0xF00 ) + ( ( V_2 -> V_10 [ 1 ] << 0 ) & 0x0FF ) ;
if ( V_8 == 0 ) {
F_3 ( V_2 , V_4 , V_7 ) ;
return 0 ;
}
if ( ( V_6 = F_4 ( V_8 , V_4 ) ) != NULL ) {
int V_11 = 1 ;
F_5 ( V_2 ) ;
F_6 ( V_6 ) ;
if ( ! F_7 ( V_6 ) ) {
V_11 = F_8 ( V_6 , V_2 ) ;
} else {
V_11 = ! F_9 ( V_6 , V_2 , V_6 -> V_12 ) ;
}
F_10 ( V_6 ) ;
F_11 ( V_6 ) ;
return V_11 ;
}
if ( V_7 == V_13 )
return F_12 ( V_2 , V_4 , V_8 ) ;
if ( F_13 ( V_8 , V_4 , V_2 ) ) {
if ( V_7 == V_14 ) {
F_14 ( V_8 ) ;
}
F_15 ( V_2 ) ;
return 1 ;
}
if ( V_7 != V_14 )
F_16 ( V_15 L_1 , V_7 ) ;
return 0 ;
}
int F_17 ( struct V_1 * V_2 , struct V_16 * V_17 ,
struct V_18 * V_19 , struct V_16 * V_20 )
{
struct V_1 * V_21 ;
struct V_3 * V_4 ;
if ( ! F_18 ( F_19 ( V_17 ) , & V_22 ) )
goto V_23;
V_21 = F_20 ( V_2 , V_24 ) ;
if ( ! V_21 )
goto V_23;
F_15 ( V_2 ) ;
V_2 = V_21 ;
V_4 = F_21 ( V_17 ) ;
if ( ! V_4 ) {
F_16 ( V_15 L_2 , V_17 -> V_25 ) ;
goto V_23;
}
if ( ! F_2 ( V_2 , 1 ) )
return 0 ;
switch ( V_2 -> V_10 [ 0 ] ) {
case V_26 :
F_22 ( V_2 , 1 ) ;
if ( F_1 ( V_2 , V_4 ) ) {
F_23 ( V_4 ) ;
goto V_27;
}
break;
case V_28 :
F_24 ( V_4 ) ;
break;
case V_29 :
F_25 ( V_4 ) ;
break;
}
F_23 ( V_4 ) ;
V_23:
F_15 ( V_2 ) ;
V_27:
return 0 ;
}
void F_26 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
unsigned char * V_30 ;
switch ( V_4 -> V_17 -> type ) {
case V_31 :
if ( ( V_2 = F_27 ( 1 , V_24 ) ) == NULL ) {
F_16 ( V_32 L_3 ) ;
return;
}
V_30 = F_28 ( V_2 , 1 ) ;
* V_30 = V_28 ;
break;
#if F_29 ( V_33 )
case V_34 :
return;
#endif
default:
return;
}
V_2 -> V_35 = F_30 ( V_36 ) ;
V_2 -> V_17 = V_4 -> V_17 ;
F_31 ( V_2 ) ;
}
void F_32 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
unsigned char * V_30 ;
#if F_29 ( V_33 )
if ( V_4 -> V_17 -> type == V_34 )
return;
#endif
if ( V_4 -> V_17 -> type != V_31 )
return;
V_2 = F_27 ( 1 , V_24 ) ;
if ( ! V_2 ) {
F_16 ( V_32 L_3 ) ;
return;
}
V_30 = F_28 ( V_2 , 1 ) ;
* V_30 = V_29 ;
V_2 -> V_35 = F_30 ( V_36 ) ;
V_2 -> V_17 = V_4 -> V_17 ;
F_31 ( V_2 ) ;
}
void F_33 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned char * V_37 ;
F_34 ( V_2 ) ;
switch ( V_4 -> V_17 -> type ) {
case V_31 :
V_37 = F_35 ( V_2 , 1 ) ;
* V_37 = V_26 ;
break;
#if F_29 ( V_33 )
case V_34 :
F_15 ( V_2 ) ;
return;
#endif
default:
F_15 ( V_2 ) ;
return;
}
V_2 -> V_35 = F_30 ( V_36 ) ;
V_2 -> V_17 = V_4 -> V_17 ;
F_31 ( V_2 ) ;
}
