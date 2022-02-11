static T_1 F_1 ( T_2 V_1 , char * V_2 )
{
char * V_3 ;
if ( F_2 ( V_1 , V_4 ) )
V_3 = L_1 ;
else if ( F_2 ( V_1 , V_5 ) )
V_3 = L_2 ;
else
V_3 = L_3 ;
return snprintf ( V_2 , V_6 , L_4 , V_3 ) ;
}
static T_1 F_3 ( T_2 V_1 , const char * V_2 , T_3 V_7 )
{
if ( ! strncasecmp ( V_2 , L_1 , 5 ) ) {
F_4 ( V_1 , V_4 ) ;
F_5 ( V_1 , V_5 ) ;
} else if ( ! strncasecmp ( V_2 , L_2 , 4 ) ) {
F_4 ( V_1 , V_5 ) ;
F_5 ( V_1 , V_4 ) ;
} else if ( ! strncasecmp ( V_2 , L_3 , 3 ) ) {
F_5 ( V_1 , V_5 ) ;
F_5 ( V_1 , V_4 ) ;
} else
return - V_8 ;
return V_7 ;
}
static T_1 F_6 ( struct V_9 * V_10 , struct V_11 * V_12 ,
char * V_2 )
{
struct V_13 * V_14 = F_7 ( V_12 ) ;
return F_1 ( V_14 -> V_1 , V_2 ) ;
}
static T_1 F_8 ( struct V_9 * V_10 , struct V_11 * V_12 ,
const char * V_2 , T_3 V_7 )
{
struct V_13 * V_14 = F_7 ( V_12 ) ;
return F_3 ( V_14 -> V_1 , V_2 , V_7 ) ;
}
int F_9 ( struct V_15 * V_16 )
{
int V_17 = 0 ;
while ( V_18 [ V_17 ] . V_12 . V_19 ) {
V_20 [ V_17 ] = & V_18 [ V_17 ] . V_12 ;
V_17 ++ ;
}
V_20 [ V_17 ] = NULL ;
F_10 ( & V_21 . V_22 , L_5 ) ;
V_21 . V_22 . V_15 = V_16 ;
return F_11 ( & V_21 ) ;
}
void F_12 ( void )
{
F_13 ( & V_21 ) ;
}
