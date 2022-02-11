static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
static int V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
const char * V_10 ;
int V_11 , V_12 = 0 ;
if ( V_5 >= V_13 )
return - V_14 ;
if ( ! V_15 [ V_5 ] ) {
V_5 ++ ;
return - V_16 ;
}
V_11 = F_2 ( V_17 [ V_5 ] , V_18 [ V_5 ] , V_19 , 0 , & V_7 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( ( V_11 = F_3 ( V_7 , V_2 ,
V_20 [ V_5 ] ,
( ( V_2 -> V_21 << 16 ) | V_2 -> V_22 ) == V_23 ? 1 : 2 ,
V_24 [ V_5 ] ,
& V_9 ) ) < 0 ) {
F_4 ( V_7 ) ;
return V_11 ;
}
V_7 -> V_25 = V_9 ;
switch ( V_9 -> V_22 ) {
case V_26 :
V_10 = L_1 ;
break;
case V_27 :
V_10 = L_2 ;
break;
case V_23 :
V_10 = L_3 ;
break;
default:
V_10 = L_4 ;
}
strcpy ( V_7 -> V_28 , V_10 ) ;
if ( V_9 -> V_22 == V_23 ) {
strcpy ( V_7 -> V_29 , L_5 ) ;
} else {
strcpy ( V_7 -> V_29 , L_6 ) ;
}
strcat ( V_7 -> V_29 , V_7 -> V_28 ) ;
sprintf ( V_7 -> V_30 , L_7 ,
V_7 -> V_29 , V_9 -> V_31 , V_9 -> V_32 ) ;
if ( ( V_11 = F_5 ( V_9 , V_12 ++ , NULL ) ) < 0 ) {
F_4 ( V_7 ) ;
return V_11 ;
}
switch ( V_9 -> V_22 ) {
case V_26 :
case V_27 :
if ( ( V_11 = F_6 ( V_9 , V_12 ++ , NULL ) ) < 0 ) {
F_4 ( V_7 ) ;
return V_11 ;
}
break;
}
if ( V_9 -> V_22 == V_27 || V_9 -> V_22 == V_23 ) {
if ( ( V_11 = F_7 ( V_9 , V_12 ++ , NULL ) ) < 0 ) {
F_4 ( V_7 ) ;
return V_11 ;
}
}
if ( V_9 -> V_22 != V_23 &&
( V_11 = F_8 ( V_7 , 0 , V_33 ,
V_9 -> V_34 ,
V_35 |
V_36 ,
- 1 , & V_9 -> V_37 ) ) < 0 ) {
F_4 ( V_7 ) ;
return V_11 ;
}
F_9 ( V_9 ) ;
if ( ( V_11 = F_10 ( V_7 ) ) < 0 ) {
F_4 ( V_7 ) ;
return V_11 ;
}
F_11 ( V_2 , V_7 ) ;
V_5 ++ ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_4 ( F_13 ( V_2 ) ) ;
}
