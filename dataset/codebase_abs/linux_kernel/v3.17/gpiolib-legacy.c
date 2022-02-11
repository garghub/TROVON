void F_1 ( unsigned V_1 )
{
F_2 ( F_3 ( V_1 ) ) ;
}
int F_4 ( unsigned V_1 , unsigned long V_2 , const char * V_3 )
{
struct V_4 * V_5 ;
int V_6 ;
V_5 = F_3 ( V_1 ) ;
V_6 = F_5 ( V_5 , V_3 ) ;
if ( V_6 )
return V_6 ;
if ( V_2 & V_7 )
F_6 ( V_8 , & V_5 -> V_2 ) ;
if ( V_2 & V_9 )
F_6 ( V_10 , & V_5 -> V_2 ) ;
if ( V_2 & V_11 )
F_6 ( V_12 , & V_5 -> V_2 ) ;
if ( V_2 & V_13 )
V_6 = F_7 ( V_5 ) ;
else
V_6 = F_8 ( V_5 ,
( V_2 & V_14 ) ? 1 : 0 ) ;
if ( V_6 )
goto V_15;
if ( V_2 & V_16 ) {
V_6 = F_9 ( V_5 , V_2 & V_17 ) ;
if ( V_6 )
goto V_15;
}
return 0 ;
V_15:
F_2 ( V_5 ) ;
return V_6 ;
}
int F_10 ( unsigned V_1 , const char * V_3 )
{
return F_5 ( F_3 ( V_1 ) , V_3 ) ;
}
int F_11 ( const struct V_1 * V_18 , T_1 V_19 )
{
int V_20 , V_6 ;
for ( V_20 = 0 ; V_20 < V_19 ; V_20 ++ , V_18 ++ ) {
V_6 = F_4 ( V_18 -> V_1 , V_18 -> V_2 , V_18 -> V_3 ) ;
if ( V_6 )
goto V_21;
}
return 0 ;
V_21:
while ( V_20 -- )
F_1 ( ( -- V_18 ) -> V_1 ) ;
return V_6 ;
}
void F_12 ( const struct V_1 * V_18 , T_1 V_19 )
{
while ( V_19 -- )
F_1 ( ( V_18 ++ ) -> V_1 ) ;
}
