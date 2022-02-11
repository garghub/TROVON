static T_1 F_1 ( int V_1 , char * V_2 , T_1 V_3 )
{
snprintf ( V_2 , V_3 , L_1 , V_1 ) ;
return strlen ( V_2 ) ;
}
static int F_2 ( struct V_4 * V_4 , struct V_5 * V_5 )
{
V_5 -> V_6 = V_4 -> V_7 ;
return 0 ;
}
static T_2 F_3 ( struct V_5 * V_5 , char T_3 * V_8 ,
T_1 V_9 , T_4 * V_10 )
{
int V_11 , V_12 , V_13 ;
T_1 V_14 = 0 ;
T_4 V_15 = 0 ;
T_2 V_16 ;
int V_17 ;
struct V_18 * V_19 = V_5 -> V_6 ;
char * V_2 ;
unsigned int V_20 ;
if ( * V_10 < 0 || ! V_9 )
return - V_21 ;
V_2 = F_4 ( V_9 , V_22 ) ;
if ( ! V_2 )
return - V_23 ;
V_11 = F_1 ( V_19 -> V_24 , V_2 , V_9 ) ;
V_12 = 2 * V_19 -> V_25 . V_26 ;
V_13 = V_11 + V_12 + 3 ;
for ( V_17 = 0 ; V_17 < V_19 -> V_24 + 1 ; V_17 ++ ) {
if ( ! F_5 ( V_19 , V_17 ) )
continue;
if ( F_6 ( V_19 , V_17 ) )
continue;
if ( V_15 >= * V_10 ) {
if ( V_14 >= V_9 - 1 - V_13 )
break;
snprintf ( V_2 + V_14 , V_9 - V_14 , L_2 ,
V_11 , V_17 ) ;
V_14 += V_11 + 2 ;
V_16 = F_7 ( V_19 , V_17 , & V_20 ) ;
if ( V_16 == 0 )
snprintf ( V_2 + V_14 , V_9 - V_14 ,
L_3 , V_12 , V_20 ) ;
else
memset ( V_2 + V_14 , 'X' , V_12 ) ;
V_14 += 2 * V_19 -> V_25 . V_26 ;
V_2 [ V_14 ++ ] = '\n' ;
}
V_15 += V_13 ;
}
V_16 = V_14 ;
if ( F_8 ( V_8 , V_2 , V_14 ) ) {
V_16 = - V_27 ;
goto V_28;
}
* V_10 += V_14 ;
V_28:
F_9 ( V_2 ) ;
return V_16 ;
}
static T_2 F_10 ( struct V_5 * V_5 ,
char T_3 * V_8 , T_1 V_9 ,
T_4 * V_10 )
{
int V_11 , V_13 ;
T_1 V_14 = 0 ;
T_4 V_15 = 0 ;
T_2 V_16 ;
int V_17 ;
struct V_18 * V_19 = V_5 -> V_6 ;
char * V_2 ;
if ( * V_10 < 0 || ! V_9 )
return - V_21 ;
V_2 = F_4 ( V_9 , V_22 ) ;
if ( ! V_2 )
return - V_23 ;
V_11 = F_1 ( V_19 -> V_24 , V_2 , V_9 ) ;
V_13 = V_11 + 10 ;
for ( V_17 = 0 ; V_17 < V_19 -> V_24 + 1 ; V_17 ++ ) {
if ( ! F_5 ( V_19 , V_17 ) && ! F_11 ( V_19 , V_17 ) )
continue;
if ( V_15 >= * V_10 ) {
if ( V_14 >= V_9 - 1 - V_13 )
break;
snprintf ( V_2 + V_14 , V_9 - V_14 ,
L_4 ,
V_11 , V_17 ,
F_5 ( V_19 , V_17 ) ? 'y' : 'n' ,
F_11 ( V_19 , V_17 ) ? 'y' : 'n' ,
F_12 ( V_19 , V_17 ) ? 'y' : 'n' ,
F_6 ( V_19 , V_17 ) ? 'y' : 'n' ) ;
V_14 += V_13 ;
}
V_15 += V_13 ;
}
V_16 = V_14 ;
if ( F_8 ( V_8 , V_2 , V_14 ) ) {
V_16 = - V_27 ;
goto V_28;
}
* V_10 += V_14 ;
V_28:
F_9 ( V_2 ) ;
return V_16 ;
}
void F_13 ( struct V_18 * V_19 )
{
V_19 -> V_29 = F_14 ( F_15 ( V_19 -> V_30 ) ,
V_31 ) ;
if ( ! V_19 -> V_29 ) {
F_16 ( V_19 -> V_30 , L_5 ) ;
return;
}
if ( V_19 -> V_24 ) {
F_17 ( L_6 , 0400 , V_19 -> V_29 ,
V_19 , & V_32 ) ;
F_17 ( L_7 , 0400 , V_19 -> V_29 ,
V_19 , & V_33 ) ;
}
}
void F_18 ( struct V_18 * V_19 )
{
F_19 ( V_19 -> V_29 ) ;
}
void F_20 ( void )
{
V_31 = F_14 ( L_8 , NULL ) ;
if ( ! V_31 ) {
F_21 ( L_9 ) ;
return;
}
}
