STATIC inline int T_1 F_1 ( T_2 * V_1 , int V_2 ,
int (* F_2) ( void * , unsigned int ) ,
int (* F_3) ( void * , unsigned int ) ,
T_2 * V_3 , int * V_4 ,
void (* error) ( char * V_5 ) )
{
int V_6 = - 1 ;
T_3 V_7 = 0 ;
T_3 V_8 = V_9 ;
T_2 * V_10 ;
T_2 * V_11 ;
T_2 * V_12 ;
int V_13 = V_2 ;
#ifdef F_4
T_3 V_14 = F_5 ( V_1 + V_2 ) ;
#endif
T_3 V_15 ;
if ( V_3 ) {
V_12 = V_3 ;
} else if ( ! F_3 ) {
error ( L_1 ) ;
goto V_16;
} else {
V_12 = F_6 ( V_8 ) ;
if ( ! V_12 ) {
error ( L_2 ) ;
goto V_16;
}
}
if ( V_1 && F_2 ) {
error ( L_3 ) ;
goto V_17;
} else if ( V_1 ) {
V_10 = V_1 ;
} else if ( ! F_2 ) {
error ( L_4 ) ;
goto V_17;
} else {
V_10 = F_6 ( F_7 ( V_8 ) ) ;
if ( ! V_10 ) {
error ( L_5 ) ;
goto V_17;
}
}
V_11 = V_10 ;
if ( V_4 )
* V_4 = 0 ;
if ( F_2 )
F_2 ( V_10 , 4 ) ;
V_7 = F_5 ( V_10 ) ;
if ( V_7 == V_18 ) {
V_10 += 4 ;
V_13 -= 4 ;
} else {
error ( L_6 ) ;
goto V_19;
}
if ( V_4 )
* V_4 += 4 ;
for (; ; ) {
if ( F_2 )
F_2 ( V_10 , 4 ) ;
V_7 = F_5 ( V_10 ) ;
if ( V_7 == V_18 ) {
V_10 += 4 ;
V_13 -= 4 ;
if ( V_4 )
* V_4 += 4 ;
continue;
}
V_10 += 4 ;
V_13 -= 4 ;
if ( V_4 )
* V_4 += 4 ;
if ( F_2 ) {
if ( V_7 > F_7 ( V_8 ) ) {
error ( L_7 ) ;
goto V_19;
}
F_2 ( V_10 , V_7 ) ;
}
#ifdef F_4
if ( V_14 >= V_8 ) {
V_15 = V_8 ;
V_14 -= V_15 ;
} else
V_15 = V_14 ;
V_6 = F_8 ( V_10 , & V_7 , V_12 , V_15 ) ;
#else
V_15 = V_8 ;
V_6 = F_9 ( V_10 , V_7 , V_12 ,
& V_15 ) ;
#endif
if ( V_6 < 0 ) {
error ( L_8 ) ;
goto V_19;
}
V_6 = - 1 ;
if ( F_3 && F_3 ( V_12 , V_15 ) != V_15 )
goto V_19;
if ( V_3 )
V_12 += V_15 ;
if ( V_4 )
* V_4 += V_7 ;
V_13 -= V_7 ;
if ( V_13 == 0 )
break;
else if ( V_13 < 0 ) {
error ( L_9 ) ;
goto V_19;
}
V_10 += V_7 ;
if ( F_2 )
V_10 = V_11 ;
}
V_6 = 0 ;
V_19:
if ( ! V_1 )
F_10 ( V_11 ) ;
V_17:
if ( ! V_3 )
F_10 ( V_12 ) ;
V_16:
return V_6 ;
}
STATIC int T_1 F_11 ( unsigned char * V_20 , int V_2 ,
int (* F_2)( void * , unsigned int ) ,
int (* F_3)( void * , unsigned int ) ,
unsigned char * V_3 ,
int * V_4 ,
void (* error)( char * V_5 )
)
{
return F_1 ( V_20 , V_2 - 4 , F_2 , F_3 , V_3 , V_4 , error ) ;
}
