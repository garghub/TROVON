static T_1 F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 ;
T_1 V_5 = 0 ;
const char * V_6 ;
void * V_7 ;
T_2 V_8 ;
if ( F_2 ( V_2 -> V_9 . V_10 , L_1 , & V_6 ) ) {
F_3 ( & V_2 -> V_9 , L_2 ) ;
return 0 ;
}
F_4 ( & V_2 -> V_9 , L_3 , V_6 ) ;
if ( F_5 ( & V_4 , V_6 , & V_2 -> V_9 ) ) {
F_3 ( & V_2 -> V_9 , L_4 , V_6 ) ;
return 0 ;
}
V_8 = V_4 -> V_8 + V_11 ;
V_7 = F_6 ( & V_2 -> V_9 , V_8 , & V_5 , V_12 ) ;
if ( V_7 ) {
V_7 = F_7 ( V_7 , V_11 ) ;
V_5 = F_8 ( V_5 , V_11 ) ;
memcpy ( V_7 , V_4 -> V_13 , V_4 -> V_8 ) ;
} else {
F_3 ( & V_2 -> V_9 , L_5 ) ;
}
F_9 ( V_4 ) ;
return V_5 ;
}
static int F_10 ( struct V_1 * V_2 )
{
T_1 V_7 ;
struct V_14 * V_15 ;
unsigned char * V_16 ;
int V_17 , V_18 = 0 ;
V_7 = F_1 ( V_2 ) ;
if ( ! V_7 )
return - V_19 ;
V_15 = F_11 ( V_2 -> V_9 . V_10 , L_6 , NULL ) ;
if ( ! V_15 )
return - V_20 ;
V_16 = V_15 -> V_21 ;
for ( V_17 = 0 ; V_17 < V_15 -> V_22 && ! V_18 ; V_17 ++ )
V_18 = F_12 ( & V_2 -> V_9 , V_16 [ V_17 ] , V_7 ) ;
if ( ! V_18 )
F_13 ( 100 ) ;
return V_18 ;
}
