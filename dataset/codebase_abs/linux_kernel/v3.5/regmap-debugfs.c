static T_1 F_1 ( int V_1 , char * V_2 , T_1 V_3 )
{
snprintf ( V_2 , V_3 , L_1 , V_1 ) ;
return strlen ( V_2 ) ;
}
static T_2 F_2 ( struct V_4 * V_4 ,
char T_3 * V_5 , T_1 V_6 ,
T_4 * V_7 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
int V_11 ;
char * V_2 ;
V_2 = F_3 ( V_12 , V_13 ) ;
if ( ! V_2 )
return - V_14 ;
V_11 = snprintf ( V_2 , V_12 , L_2 , V_9 -> V_15 -> V_16 -> V_17 ) ;
if ( V_11 < 0 ) {
F_4 ( V_2 ) ;
return V_11 ;
}
V_11 = F_5 ( V_5 , V_6 , V_7 , V_2 , V_11 ) ;
F_4 ( V_2 ) ;
return V_11 ;
}
static T_2 F_6 ( struct V_4 * V_4 , char T_3 * V_5 ,
T_1 V_6 , T_4 * V_7 )
{
int V_18 , V_19 , V_20 ;
T_1 V_21 = 0 ;
T_4 V_22 = 0 ;
T_2 V_11 ;
int V_23 ;
struct V_8 * V_9 = V_4 -> V_10 ;
char * V_2 ;
unsigned int V_24 ;
if ( * V_7 < 0 || ! V_6 )
return - V_25 ;
V_2 = F_3 ( V_6 , V_13 ) ;
if ( ! V_2 )
return - V_14 ;
V_18 = F_1 ( V_9 -> V_26 , V_2 , V_6 ) ;
V_19 = 2 * V_9 -> V_27 . V_28 ;
V_20 = V_18 + V_19 + 3 ;
for ( V_23 = 0 ; V_23 <= V_9 -> V_26 ; V_23 += V_9 -> V_29 ) {
if ( ! F_7 ( V_9 , V_23 ) )
continue;
if ( F_8 ( V_9 , V_23 ) )
continue;
if ( V_22 >= * V_7 ) {
if ( V_21 >= V_6 - 1 - V_20 )
break;
snprintf ( V_2 + V_21 , V_6 - V_21 , L_3 ,
V_18 , V_23 ) ;
V_21 += V_18 + 2 ;
V_11 = F_9 ( V_9 , V_23 , & V_24 ) ;
if ( V_11 == 0 )
snprintf ( V_2 + V_21 , V_6 - V_21 ,
L_4 , V_19 , V_24 ) ;
else
memset ( V_2 + V_21 , 'X' , V_19 ) ;
V_21 += 2 * V_9 -> V_27 . V_28 ;
V_2 [ V_21 ++ ] = '\n' ;
}
V_22 += V_20 ;
}
V_11 = V_21 ;
if ( F_10 ( V_5 , V_2 , V_21 ) ) {
V_11 = - V_30 ;
goto V_31;
}
* V_7 += V_21 ;
V_31:
F_4 ( V_2 ) ;
return V_11 ;
}
static T_2 F_11 ( struct V_4 * V_4 ,
const char T_3 * V_5 ,
T_1 V_6 , T_4 * V_7 )
{
char V_2 [ 32 ] ;
T_1 V_3 ;
char * V_32 = V_2 ;
unsigned long V_33 , V_34 ;
struct V_8 * V_9 = V_4 -> V_10 ;
V_3 = F_12 ( V_6 , ( sizeof( V_2 ) - 1 ) ) ;
if ( F_13 ( V_2 , V_5 , V_3 ) )
return - V_30 ;
V_2 [ V_3 ] = 0 ;
while ( * V_32 == ' ' )
V_32 ++ ;
V_33 = F_14 ( V_32 , & V_32 , 16 ) ;
while ( * V_32 == ' ' )
V_32 ++ ;
if ( F_15 ( V_32 , 16 , & V_34 ) )
return - V_25 ;
F_16 ( V_35 ) ;
F_17 ( V_9 , V_33 , V_34 ) ;
return V_3 ;
}
static T_2 F_18 ( struct V_4 * V_4 ,
char T_3 * V_5 , T_1 V_6 ,
T_4 * V_7 )
{
int V_18 , V_20 ;
T_1 V_21 = 0 ;
T_4 V_22 = 0 ;
T_2 V_11 ;
int V_23 ;
struct V_8 * V_9 = V_4 -> V_10 ;
char * V_2 ;
if ( * V_7 < 0 || ! V_6 )
return - V_25 ;
V_2 = F_3 ( V_6 , V_13 ) ;
if ( ! V_2 )
return - V_14 ;
V_18 = F_1 ( V_9 -> V_26 , V_2 , V_6 ) ;
V_20 = V_18 + 10 ;
for ( V_23 = 0 ; V_23 <= V_9 -> V_26 ; V_23 += V_9 -> V_29 ) {
if ( ! F_7 ( V_9 , V_23 ) && ! F_19 ( V_9 , V_23 ) )
continue;
if ( V_22 >= * V_7 ) {
if ( V_21 >= V_6 - 1 - V_20 )
break;
snprintf ( V_2 + V_21 , V_6 - V_21 ,
L_5 ,
V_18 , V_23 ,
F_7 ( V_9 , V_23 ) ? 'y' : 'n' ,
F_19 ( V_9 , V_23 ) ? 'y' : 'n' ,
F_20 ( V_9 , V_23 ) ? 'y' : 'n' ,
F_8 ( V_9 , V_23 ) ? 'y' : 'n' ) ;
V_21 += V_20 ;
}
V_22 += V_20 ;
}
V_11 = V_21 ;
if ( F_10 ( V_5 , V_2 , V_21 ) ) {
V_11 = - V_30 ;
goto V_31;
}
* V_7 += V_21 ;
V_31:
F_4 ( V_2 ) ;
return V_11 ;
}
void F_21 ( struct V_8 * V_9 , const char * V_17 )
{
if ( V_17 ) {
V_9 -> V_36 = F_22 ( V_13 , L_6 ,
F_23 ( V_9 -> V_15 ) , V_17 ) ;
V_17 = V_9 -> V_36 ;
} else {
V_17 = F_23 ( V_9 -> V_15 ) ;
}
V_9 -> V_37 = F_24 ( V_17 , V_38 ) ;
if ( ! V_9 -> V_37 ) {
F_25 ( V_9 -> V_15 , L_7 ) ;
return;
}
F_26 ( L_8 , 0400 , V_9 -> V_37 ,
V_9 , & V_39 ) ;
if ( V_9 -> V_26 ) {
F_26 ( L_9 , 0400 , V_9 -> V_37 ,
V_9 , & V_40 ) ;
F_26 ( L_10 , 0400 , V_9 -> V_37 ,
V_9 , & V_41 ) ;
}
if ( V_9 -> V_42 ) {
F_27 ( L_11 , 0400 , V_9 -> V_37 ,
& V_9 -> V_43 ) ;
F_27 ( L_12 , 0400 , V_9 -> V_37 ,
& V_9 -> V_44 ) ;
F_27 ( L_13 , 0400 , V_9 -> V_37 ,
& V_9 -> V_45 ) ;
}
}
void F_28 ( struct V_8 * V_9 )
{
F_29 ( V_9 -> V_37 ) ;
F_4 ( V_9 -> V_36 ) ;
}
void F_30 ( void )
{
V_38 = F_24 ( L_14 , NULL ) ;
if ( ! V_38 ) {
F_31 ( L_15 ) ;
return;
}
}
