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
F_16 ( L_1 , V_7 ) ;
return 0 ;
}
int F_17 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_17 * V_18 , struct V_15 * V_19 )
{
struct V_1 * V_20 ;
struct V_3 * V_4 ;
if ( ! F_18 ( F_19 ( V_16 ) , & V_21 ) )
goto V_22;
V_20 = F_20 ( V_2 , V_23 ) ;
if ( ! V_20 )
goto V_22;
F_15 ( V_2 ) ;
V_2 = V_20 ;
V_4 = F_21 ( V_16 ) ;
if ( ! V_4 ) {
F_16 ( L_2 , V_16 -> V_24 ) ;
goto V_22;
}
if ( ! F_2 ( V_2 , 1 ) )
return 0 ;
switch ( V_2 -> V_10 [ 0 ] ) {
case V_25 :
F_22 ( V_2 , 1 ) ;
if ( F_1 ( V_2 , V_4 ) ) {
F_23 ( V_4 ) ;
goto V_26;
}
break;
case V_27 :
F_24 ( V_4 ) ;
break;
case V_28 :
F_25 ( V_4 ) ;
break;
}
F_23 ( V_4 ) ;
V_22:
F_15 ( V_2 ) ;
V_26:
return 0 ;
}
void F_26 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
unsigned char * V_29 ;
switch ( V_4 -> V_16 -> type ) {
case V_30 :
if ( ( V_2 = F_27 ( 1 , V_23 ) ) == NULL ) {
F_28 ( L_3 ) ;
return;
}
V_29 = F_29 ( V_2 , 1 ) ;
* V_29 = V_27 ;
break;
#if F_30 ( V_31 )
case V_32 :
return;
#endif
default:
return;
}
V_2 -> V_33 = F_31 ( V_34 ) ;
V_2 -> V_16 = V_4 -> V_16 ;
F_32 ( V_2 ) ;
}
void F_33 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
unsigned char * V_29 ;
#if F_30 ( V_31 )
if ( V_4 -> V_16 -> type == V_32 )
return;
#endif
if ( V_4 -> V_16 -> type != V_30 )
return;
V_2 = F_27 ( 1 , V_23 ) ;
if ( ! V_2 ) {
F_28 ( L_3 ) ;
return;
}
V_29 = F_29 ( V_2 , 1 ) ;
* V_29 = V_28 ;
V_2 -> V_33 = F_31 ( V_34 ) ;
V_2 -> V_16 = V_4 -> V_16 ;
F_32 ( V_2 ) ;
}
void F_34 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned char * V_35 ;
F_35 ( V_2 ) ;
switch ( V_4 -> V_16 -> type ) {
case V_30 :
V_35 = F_36 ( V_2 , 1 ) ;
* V_35 = V_25 ;
break;
#if F_30 ( V_31 )
case V_32 :
F_15 ( V_2 ) ;
return;
#endif
default:
F_15 ( V_2 ) ;
return;
}
V_2 -> V_33 = F_31 ( V_34 ) ;
V_2 -> V_16 = V_4 -> V_16 ;
F_32 ( V_2 ) ;
}
