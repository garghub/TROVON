void F_1 ( struct V_1 * V_1 , const char * V_2 )
{
int V_3 = 128 ,
V_4 ;
struct V_5 V_6 ;
if ( ! V_1 ) {
F_2 ( V_7 L_1 ,
V_8 ) ;
return;
}
if ( ! V_2 )
goto V_9;
V_4 = strlen ( V_2 ) ;
if ( ! V_4 )
goto V_9;
{
char V_10 [ V_4 + 1 ] ;
char * V_11 , * V_12 , * V_13 , * V_14 ;
int V_15 ;
strcpy ( V_10 , V_2 ) ;
V_11 = V_10 ;
while ( ( V_12 = F_3 ( & V_11 , L_2 ) ) ) {
if ( ! strlen ( V_12 ) )
continue;
V_13 = F_3 ( & V_12 , L_3 ) ;
V_14 = V_12 ;
if ( ! V_14 )
continue;
if ( ! strcmp ( V_13 , L_4 ) ) {
if ( sscanf ( V_14 , L_5 , & V_15 ) == 1 )
V_3 = V_15 ;
}
}
}
V_9:
F_2 ( V_16 L_6 ,
V_8 , V_3 ) ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_17 = V_18 ;
V_6 . V_19 = V_3 ;
if ( ! V_1 -> V_20 . V_21 -> V_22 ( & V_1 -> V_20 , V_23 , & V_6 ) ) {
F_2 ( V_16 L_7 ,
V_8 ) ;
return;
}
}
void F_4 ( struct V_1 * V_1 )
{
struct V_5 V_6 ;
if ( ! V_1 ) {
F_2 ( V_7 L_8 ,
V_8 ) ;
return;
}
F_2 ( V_16 L_9 , V_8 ) ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_17 = V_24 ;
if ( ! V_1 -> V_20 . V_21 -> V_22 ( & V_1 -> V_20 , V_23 , & V_6 ) ) {
F_2 ( V_16 L_7 ,
V_8 ) ;
return;
}
}
int F_5 ( void )
{
F_6 ( V_25 ) ;
return 0 ;
}
void F_7 ( void )
{
F_8 ( V_25 ) ;
}
