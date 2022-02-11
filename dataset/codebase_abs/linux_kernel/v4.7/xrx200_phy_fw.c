static T_1 F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 ;
T_1 V_5 = 0 ;
const char * V_6 ;
void * V_7 ;
T_2 V_8 ;
if ( F_2 ( V_2 -> V_9 . V_10 , L_1 , NULL ) ||
F_2 ( V_2 -> V_9 . V_10 , L_2 , NULL ) ) {
switch ( F_3 () ) {
case V_11 :
if ( F_4 ( V_2 -> V_9 . V_10 ,
L_1 , & V_6 ) ) {
F_5 ( & V_2 -> V_9 ,
L_3 ) ;
return 0 ;
}
break;
case V_12 :
if ( F_4 ( V_2 -> V_9 . V_10 ,
L_2 , & V_6 ) ) {
F_5 ( & V_2 -> V_9 ,
L_3 ) ;
return 0 ;
}
break;
}
} else if ( F_4 ( V_2 -> V_9 . V_10 ,
L_4 , & V_6 ) ) {
F_5 ( & V_2 -> V_9 , L_3 ) ;
return 0 ;
}
F_6 ( & V_2 -> V_9 , L_5 , V_6 ) ;
if ( F_7 ( & V_4 , V_6 , & V_2 -> V_9 ) ) {
F_5 ( & V_2 -> V_9 , L_6 , V_6 ) ;
return 0 ;
}
V_8 = V_4 -> V_8 + V_13 ;
V_7 = F_8 ( & V_2 -> V_9 , V_8 , & V_5 , V_14 ) ;
if ( V_7 ) {
V_7 = F_9 ( V_7 , V_13 ) ;
V_5 = F_10 ( V_5 , V_13 ) ;
memcpy ( V_7 , V_4 -> V_15 , V_4 -> V_8 ) ;
} else {
F_5 ( & V_2 -> V_9 , L_7 ) ;
}
F_11 ( V_4 ) ;
return V_5 ;
}
static int F_12 ( struct V_1 * V_2 )
{
T_1 V_7 ;
struct V_16 * V_17 ;
unsigned char * V_18 ;
int V_19 , V_20 = 0 ;
V_7 = F_1 ( V_2 ) ;
if ( ! V_7 )
return - V_21 ;
V_17 = F_13 ( V_2 -> V_9 . V_10 , L_8 , NULL ) ;
if ( ! V_17 )
return - V_22 ;
V_18 = V_17 -> V_23 ;
for ( V_19 = 0 ; V_19 < V_17 -> V_24 && ! V_20 ; V_19 ++ )
V_20 = F_14 ( & V_2 -> V_9 , V_18 [ V_19 ] , V_7 ) ;
if ( ! V_20 )
F_15 ( 100 ) ;
return V_20 ;
}
