static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
unsigned short V_7 ;
unsigned int V_8 ;
V_7 = V_2 -> V_9 [ 2 ] ;
V_8 = ( ( V_2 -> V_9 [ 0 ] << 8 ) & 0xF00 ) + ( ( V_2 -> V_9 [ 1 ] << 0 ) & 0x0FF ) ;
if ( V_8 == 0 ) {
F_2 ( V_2 , V_4 , V_7 ) ;
return 0 ;
}
if ( ( V_6 = F_3 ( V_8 , V_4 ) ) != NULL ) {
int V_10 = 1 ;
F_4 ( V_2 ) ;
F_5 ( V_6 ) ;
if ( ! F_6 ( V_6 ) ) {
V_10 = F_7 ( V_6 , V_2 ) ;
} else {
V_10 = ! F_8 ( V_6 , V_2 ) ;
}
F_9 ( V_6 ) ;
F_10 ( V_6 ) ;
return V_10 ;
}
if ( V_7 == V_11 )
return F_11 ( V_2 , V_4 , V_8 ) ;
if ( F_12 ( V_8 , V_4 , V_2 ) ) {
if ( V_7 == V_12 ) {
F_13 ( V_8 ) ;
}
F_14 ( V_2 ) ;
return 1 ;
}
if ( V_7 != V_12 )
F_15 ( V_13 L_1 , V_7 ) ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 , struct V_14 * V_15 ,
struct V_16 * V_17 , struct V_14 * V_18 )
{
struct V_1 * V_19 ;
struct V_3 * V_4 ;
if ( ! F_17 ( F_18 ( V_15 ) , & V_20 ) )
goto V_21;
V_19 = F_19 ( V_2 , V_22 ) ;
if ( ! V_19 )
goto V_21;
F_14 ( V_2 ) ;
V_2 = V_19 ;
V_4 = F_20 ( V_15 ) ;
if ( ! V_4 ) {
F_15 ( V_13 L_2 , V_15 -> V_23 ) ;
goto V_21;
}
switch ( V_2 -> V_9 [ 0 ] ) {
case V_24 :
F_21 ( V_2 , 1 ) ;
if ( F_1 ( V_2 , V_4 ) ) {
F_22 ( V_4 ) ;
goto V_25;
}
break;
case V_26 :
F_23 ( V_4 ) ;
break;
case V_27 :
F_24 ( V_4 ) ;
break;
}
F_22 ( V_4 ) ;
V_21:
F_14 ( V_2 ) ;
V_25:
return 0 ;
}
void F_25 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
unsigned char * V_28 ;
switch ( V_4 -> V_15 -> type ) {
case V_29 :
if ( ( V_2 = F_26 ( 1 , V_22 ) ) == NULL ) {
F_15 ( V_30 L_3 ) ;
return;
}
V_28 = F_27 ( V_2 , 1 ) ;
* V_28 = V_26 ;
break;
#if F_28 ( V_31 ) || F_28 ( V_32 )
case V_33 :
return;
#endif
default:
return;
}
V_2 -> V_34 = F_29 ( V_35 ) ;
V_2 -> V_15 = V_4 -> V_15 ;
F_30 ( V_2 ) ;
}
void F_31 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
unsigned char * V_28 ;
#if F_28 ( V_31 ) || F_28 ( V_32 )
if ( V_4 -> V_15 -> type == V_33 )
return;
#endif
if ( V_4 -> V_15 -> type != V_29 )
return;
V_2 = F_26 ( 1 , V_22 ) ;
if ( ! V_2 ) {
F_15 ( V_30 L_3 ) ;
return;
}
V_28 = F_27 ( V_2 , 1 ) ;
* V_28 = V_27 ;
V_2 -> V_34 = F_29 ( V_35 ) ;
V_2 -> V_15 = V_4 -> V_15 ;
F_30 ( V_2 ) ;
}
void F_32 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned char * V_36 ;
F_33 ( V_2 ) ;
switch ( V_4 -> V_15 -> type ) {
case V_29 :
V_36 = F_34 ( V_2 , 1 ) ;
* V_36 = V_24 ;
break;
#if F_28 ( V_31 ) || F_28 ( V_32 )
case V_33 :
F_14 ( V_2 ) ;
return;
#endif
default:
F_14 ( V_2 ) ;
return;
}
V_2 -> V_34 = F_29 ( V_35 ) ;
V_2 -> V_15 = V_4 -> V_15 ;
F_30 ( V_2 ) ;
}
