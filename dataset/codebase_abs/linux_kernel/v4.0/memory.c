T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 * V_4 = V_2 -> V_5 . V_6 ;
T_1 V_7 =
( V_4 -> V_8 - sizeof( struct V_9 ) / 4 ) -
V_3 ;
if ( V_2 -> V_10 ) {
V_7 -= 2 ;
V_7 /= 3 ;
} else
V_7 /= 2 ;
if ( V_2 -> V_11 && ( V_7 > 8 ) )
V_7 = 8 ;
return V_7 ;
}
T_3 F_2 ( struct V_1 * V_2 , void * V_12 ,
T_4 V_13 ,
enum V_14 V_15 ,
T_5 * * V_16 )
{
T_5 V_17 ;
T_5 * V_18 = * V_16 ;
T_3 V_19 ;
switch ( V_15 ) {
case V_20 :
V_17 = 0xd4000000 ;
break;
case V_21 :
V_17 = 0xd0000000 ;
break;
default:
return 0 ;
}
V_19 = F_3 ( & V_2 -> V_22 -> V_23 , V_12 , V_13 , V_15 ) ;
if ( ! F_4 ( & V_2 -> V_22 -> V_23 , V_19 ) ) {
#ifdef F_5
if ( ( sizeof( T_3 ) > 4 ) && V_2 -> V_10 ) {
* V_18 ++ = F_6 ( 0x7C020002 ) ;
* V_18 ++ = F_6 ( V_24 ) ;
}
#endif
* V_18 ++ = F_6 ( V_17 | V_13 ) ;
* V_18 ++ = F_6 ( F_7 ( V_19 ) ) ;
#ifdef F_5
if ( ( sizeof( T_3 ) > 4 ) && V_2 -> V_10 )
* V_18 ++ = F_6 ( F_8 ( V_19 ) ) ;
#endif
* V_16 = V_18 ;
}
return V_19 ;
}
int F_9 ( struct V_1 * V_2 , struct V_25 * V_26 ,
int V_7 , enum V_14 V_15 , T_5 * * V_16 )
{
T_5 V_17 ;
T_5 * V_18 = * V_16 ;
switch ( V_15 ) {
case V_20 :
V_17 = 0x14000000 ;
break;
case V_21 :
V_17 = 0x10000000 ;
break;
default:
return 0 ;
}
V_7 = F_10 ( & V_2 -> V_22 -> V_23 , V_26 , V_7 , V_15 ) ;
if ( ! V_7 )
return 0 ;
#ifdef F_5
if ( ( sizeof( T_3 ) > 4 ) && V_2 -> V_10 ) {
* V_18 ++ = F_6 ( 0x7C020002 ) ;
* V_18 ++ = F_6 ( V_24 ) ;
}
#endif
while ( V_7 -- > 0 ) {
if ( ! V_7 )
V_17 |= 0xC0000000 ;
* V_18 ++ = F_6 ( V_17 | F_11 ( V_26 ) ) ;
* V_18 ++ = F_6 ( F_7 ( F_12 ( V_26 ) ) ) ;
#ifdef F_5
if ( ( sizeof( T_3 ) > 4 ) && V_2 -> V_10 )
* V_18 ++ = F_6 ( F_8 ( F_12 ( V_26 ) ) ) ;
#endif
V_26 = F_13 ( V_26 ) ;
}
* V_16 = V_18 ;
return 1 ;
}
int F_14 ( struct V_27 * V_23 , struct V_28 * V_29 , T_4 V_30 )
{
struct V_31 * V_22 = F_15 ( V_23 ) ;
int V_32 = 0 ;
F_16 ( & V_33 ) ;
if ( ( sizeof( T_3 ) > 4 ) && ( V_22 -> V_34 == F_17 ( 64 ) ) ) {
V_32 = 1 ;
if ( F_18 ( V_22 , F_17 ( 32 ) ) ) {
F_19 ( & V_33 ) ;
return - V_35 ;
}
}
V_29 -> V_6 = F_20 ( V_23 , V_30 , & V_29 -> V_36 , V_37 ) ;
if ( ( sizeof( T_3 ) > 4 ) && V_32 )
if ( F_18 ( V_22 , F_17 ( 64 ) ) )
F_21 ( V_38 L_1 ) ;
F_19 ( & V_33 ) ;
if ( ! V_29 -> V_6 )
return - V_35 ;
memset ( V_29 -> V_6 , 0 , V_30 ) ;
V_29 -> V_30 = V_30 ;
return 0 ;
}
void F_22 ( struct V_27 * V_23 , struct V_28 * V_29 )
{
if ( V_29 -> V_6 ) {
if ( V_29 -> V_36 )
F_23 ( V_23 , V_29 -> V_30 , V_29 -> V_6 ,
V_29 -> V_36 ) ;
else
F_24 ( V_29 -> V_6 ) ;
V_29 -> V_6 = NULL ;
}
}
int F_25 ( struct V_27 * V_23 , struct V_28 * V_29 , T_4 V_30 )
{
F_22 ( V_23 , V_29 ) ;
if ( V_30 )
return F_14 ( V_23 , V_29 , V_30 ) ;
return 0 ;
}
int F_26 ( struct V_39 * V_40 , const char * V_41 ,
T_4 V_13 , int V_42 )
{
V_40 -> V_41 = F_27 ( strlen ( V_41 ) + 1 , V_37 ) ;
if ( ! V_40 -> V_41 )
goto exit;
strcpy ( V_40 -> V_41 , V_41 ) ;
V_40 -> V_43 =
F_28 ( V_40 -> V_41 , V_13 , 0 , V_44 , NULL ) ;
if ( ! V_40 -> V_43 )
goto V_45;
V_40 -> V_46 = F_29 ( V_42 , V_40 -> V_43 ) ;
if ( ! V_40 -> V_46 )
goto V_47;
return 0 ;
V_47:
F_30 ( V_40 -> V_43 ) ;
V_45:
F_24 ( V_40 -> V_41 ) ;
exit:
return - V_35 ;
}
void F_31 ( struct V_39 * V_40 )
{
F_32 ( V_40 -> V_46 ) ;
F_30 ( V_40 -> V_43 ) ;
F_24 ( V_40 -> V_41 ) ;
}
