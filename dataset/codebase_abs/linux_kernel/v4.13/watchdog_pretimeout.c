static struct V_1 * F_1 ( const char * V_2 )
{
struct V_1 * V_3 ;
F_2 (priv, &governor_list, entry)
if ( F_3 ( V_2 , V_3 -> V_4 -> V_5 ) )
return V_3 ;
return NULL ;
}
int F_4 ( char * V_6 )
{
struct V_1 * V_3 ;
int V_7 = 0 ;
F_5 ( & V_8 ) ;
F_2 (priv, &governor_list, entry)
V_7 += sprintf ( V_6 + V_7 , L_1 , V_3 -> V_4 -> V_5 ) ;
F_6 ( & V_8 ) ;
return V_7 ;
}
int F_7 ( struct V_9 * V_10 , char * V_6 )
{
int V_7 = 0 ;
F_8 ( & V_11 ) ;
if ( V_10 -> V_4 )
V_7 = sprintf ( V_6 , L_1 , V_10 -> V_4 -> V_5 ) ;
F_9 ( & V_11 ) ;
return V_7 ;
}
int F_10 ( struct V_9 * V_10 ,
const char * V_6 )
{
struct V_1 * V_3 ;
F_5 ( & V_8 ) ;
V_3 = F_1 ( V_6 ) ;
if ( ! V_3 ) {
F_6 ( & V_8 ) ;
return - V_12 ;
}
F_8 ( & V_11 ) ;
V_10 -> V_4 = V_3 -> V_4 ;
F_9 ( & V_11 ) ;
F_6 ( & V_8 ) ;
return 0 ;
}
void F_11 ( struct V_9 * V_10 )
{
unsigned long V_13 ;
F_12 ( & V_11 , V_13 ) ;
if ( ! V_10 -> V_4 ) {
F_13 ( & V_11 , V_13 ) ;
return;
}
V_10 -> V_4 -> V_14 ( V_10 ) ;
F_13 ( & V_11 , V_13 ) ;
}
int F_14 ( struct V_15 * V_4 )
{
struct V_16 * V_17 ;
struct V_1 * V_3 ;
V_3 = F_15 ( sizeof( * V_3 ) , V_18 ) ;
if ( ! V_3 )
return - V_19 ;
F_5 ( & V_8 ) ;
if ( F_1 ( V_4 -> V_5 ) ) {
F_6 ( & V_8 ) ;
F_16 ( V_3 ) ;
return - V_20 ;
}
V_3 -> V_4 = V_4 ;
F_17 ( & V_3 -> V_21 , & V_22 ) ;
if ( ! strncmp ( V_4 -> V_5 , V_23 ,
V_24 ) ) {
F_8 ( & V_11 ) ;
V_25 = V_4 ;
F_2 (p, &pretimeout_list, entry)
if ( ! V_17 -> V_10 -> V_4 )
V_17 -> V_10 -> V_4 = V_25 ;
F_9 ( & V_11 ) ;
}
F_6 ( & V_8 ) ;
return 0 ;
}
void F_18 ( struct V_15 * V_4 )
{
struct V_16 * V_17 ;
struct V_1 * V_3 , * V_26 ;
F_5 ( & V_8 ) ;
F_19 (priv, t, &governor_list, entry) {
if ( V_3 -> V_4 == V_4 ) {
F_20 ( & V_3 -> V_21 ) ;
F_16 ( V_3 ) ;
break;
}
}
F_8 ( & V_11 ) ;
F_2 (p, &pretimeout_list, entry)
if ( V_17 -> V_10 -> V_4 == V_4 )
V_17 -> V_10 -> V_4 = V_25 ;
F_9 ( & V_11 ) ;
F_6 ( & V_8 ) ;
}
int F_21 ( struct V_9 * V_10 )
{
struct V_16 * V_17 ;
if ( ! ( V_10 -> V_27 -> V_28 & V_29 ) )
return 0 ;
V_17 = F_15 ( sizeof( * V_17 ) , V_18 ) ;
if ( ! V_17 )
return - V_19 ;
F_8 ( & V_11 ) ;
F_17 ( & V_17 -> V_21 , & V_30 ) ;
V_17 -> V_10 = V_10 ;
V_10 -> V_4 = V_25 ;
F_9 ( & V_11 ) ;
return 0 ;
}
void F_22 ( struct V_9 * V_10 )
{
struct V_16 * V_17 , * V_26 ;
if ( ! ( V_10 -> V_27 -> V_28 & V_29 ) )
return;
F_8 ( & V_11 ) ;
V_10 -> V_4 = NULL ;
F_19 (p, t, &pretimeout_list, entry) {
if ( V_17 -> V_10 == V_10 ) {
F_20 ( & V_17 -> V_21 ) ;
break;
}
}
F_9 ( & V_11 ) ;
F_16 ( V_17 ) ;
}
