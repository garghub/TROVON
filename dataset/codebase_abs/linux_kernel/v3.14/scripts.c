static int F_1 ( char * V_1 )
{
char * V_2 , * V_3 [ V_4 ] , * V_5 [ V_4 ] ;
int V_6 , V_7 , V_8 , V_9 = - 1 ;
V_2 = malloc ( V_4 * ( V_10 + V_11 ) ) ;
if ( ! V_2 )
return V_9 ;
for ( V_6 = 0 ; V_6 < V_4 ; V_6 ++ ) {
V_3 [ V_6 ] = V_2 + V_6 * ( V_10 + V_11 ) ;
V_5 [ V_6 ] = V_3 [ V_6 ] + V_10 ;
}
V_7 = F_2 ( V_3 , V_5 ) ;
if ( V_7 > 0 ) {
V_8 = F_3 ( V_7 , V_3 ) ;
if ( V_8 < V_7 && V_8 >= 0 ) {
strcpy ( V_1 , V_5 [ V_8 ] ) ;
V_9 = 0 ;
}
}
free ( V_2 ) ;
return V_9 ;
}
static void F_4 ( struct V_12 * V_13 ,
void * V_14 , int V_15 )
{
struct V_16 * V_17 = F_5 ( V_14 , struct V_16 , V_18 ) ;
bool V_19 = F_6 ( V_13 , V_15 ) ;
F_7 ( V_13 , V_19 ? V_20 :
V_21 ) ;
F_8 ( V_17 -> line , V_13 -> V_22 ) ;
}
static int F_9 ( struct V_23 * V_13 )
{
int V_24 ;
if ( F_10 ( & V_13 -> V_25 , V_13 -> V_1 ,
L_1 ) < 0 )
return - 1 ;
while ( 1 ) {
V_24 = F_11 ( & V_13 -> V_25 , 0 ) ;
break;
}
F_12 ( & V_13 -> V_25 ) ;
return V_24 ;
}
int F_13 ( const char * V_26 )
{
char V_27 [ V_11 * 2 ] , V_1 [ V_11 ] ;
char * line = NULL ;
T_1 V_28 = 0 ;
T_2 V_29 ;
int V_9 = - 1 , V_30 = 0 ;
T_3 * V_31 ;
void * V_2 ;
struct V_16 * V_17 ;
struct V_23 V_32 = {
. V_25 = {
. V_33 = V_34 ,
. V_35 = V_36 ,
. V_37 = F_4 ,
} ,
. V_1 = V_1 ,
} ;
F_14 ( & V_32 . V_38 ) ;
V_2 = F_15 ( ( sizeof( * V_17 ) ) * V_39 ) ;
if ( ! V_2 )
return - 1 ;
V_17 = V_2 ;
memset ( V_1 , 0 , V_11 ) ;
if ( F_1 ( V_1 ) )
goto exit;
sprintf ( V_27 , L_2 , V_1 ) ;
if ( V_26 )
strcat ( V_27 , V_26 ) ;
if ( V_40 ) {
strcat ( V_27 , L_3 ) ;
strcat ( V_27 , V_40 ) ;
}
strcat ( V_27 , L_4 ) ;
V_31 = F_16 ( V_27 , L_5 ) ;
if ( ! V_31 )
goto exit;
while ( ( V_29 = F_17 ( & line , & V_28 , V_31 ) ) != - 1 ) {
strncpy ( V_17 -> line , line , V_41 ) ;
if ( V_29 >= V_41 ) {
V_17 -> line [ V_41 - 1 ] = '\0' ;
V_17 -> line [ V_41 - 2 ] = '\n' ;
}
F_18 ( & V_17 -> V_18 , & V_32 . V_38 ) ;
if ( V_32 . V_25 . V_22 < V_29 )
V_32 . V_25 . V_22 = V_29 ;
if ( V_30 ++ >= V_39 - 1 )
break;
V_17 ++ ;
}
if ( V_32 . V_25 . V_22 > V_41 )
V_32 . V_25 . V_22 = V_41 ;
free ( line ) ;
F_19 ( V_31 ) ;
V_32 . V_42 = V_30 ;
V_32 . V_25 . V_30 = V_30 ;
V_32 . V_25 . V_38 = & V_32 . V_38 ;
V_9 = F_9 ( & V_32 ) ;
exit:
free ( V_2 ) ;
return V_9 ;
}
