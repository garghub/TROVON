void F_1 ( unsigned V_1 )
{
F_2 ( F_3 ( V_1 ) ) ;
}
int F_4 ( unsigned V_1 , unsigned long V_2 , const char * V_3 )
{
struct V_4 * V_5 ;
int V_6 ;
V_5 = F_3 ( V_1 ) ;
if ( ! V_5 && F_5 ( V_1 ) )
return - V_7 ;
V_6 = F_6 ( V_5 , V_3 ) ;
if ( V_6 )
return V_6 ;
if ( V_2 & V_8 )
F_7 ( V_9 , & V_5 -> V_2 ) ;
if ( V_2 & V_10 )
F_7 ( V_11 , & V_5 -> V_2 ) ;
if ( V_2 & V_12 )
F_7 ( V_13 , & V_5 -> V_2 ) ;
if ( V_2 & V_14 )
V_6 = F_8 ( V_5 ) ;
else
V_6 = F_9 ( V_5 ,
( V_2 & V_15 ) ? 1 : 0 ) ;
if ( V_6 )
goto V_16;
if ( V_2 & V_17 ) {
V_6 = F_10 ( V_5 , V_2 & V_18 ) ;
if ( V_6 )
goto V_16;
}
return 0 ;
V_16:
F_2 ( V_5 ) ;
return V_6 ;
}
int F_11 ( unsigned V_1 , const char * V_3 )
{
struct V_4 * V_5 = F_3 ( V_1 ) ;
if ( ! V_5 && F_5 ( V_1 ) )
return - V_7 ;
return F_6 ( V_5 , V_3 ) ;
}
int F_12 ( const struct V_1 * V_19 , T_1 V_20 )
{
int V_21 , V_6 ;
for ( V_21 = 0 ; V_21 < V_20 ; V_21 ++ , V_19 ++ ) {
V_6 = F_4 ( V_19 -> V_1 , V_19 -> V_2 , V_19 -> V_3 ) ;
if ( V_6 )
goto V_22;
}
return 0 ;
V_22:
while ( V_21 -- )
F_1 ( ( -- V_19 ) -> V_1 ) ;
return V_6 ;
}
void F_13 ( const struct V_1 * V_19 , T_1 V_20 )
{
while ( V_20 -- )
F_1 ( ( V_19 ++ ) -> V_1 ) ;
}
