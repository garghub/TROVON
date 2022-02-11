int F_1 ( T_1 * V_1 , const void * V_2 , int V_3 ,
const T_2 * V_4 , T_3 * V_5 )
{
int V_6 , V_7 , V_8 = 0 ;
unsigned char V_9 [ V_10 ] ;
#ifdef F_2
if ( F_3 () ) {
const T_2 * V_11 ;
if ( V_4 ) {
V_11 = F_4 ( F_5 ( V_4 ) ) ;
if ( V_11 )
V_4 = V_11 ;
}
}
if ( F_3 () ) {
if ( ( V_5 || V_1 -> V_12 . V_13 )
&& ! ( V_1 -> V_12 . V_14 & V_15 ) ) {
F_6 ( V_16 , V_17 ) ;
return 0 ;
}
if ( ! V_5 && ! V_1 -> V_12 . V_13 )
return F_7 ( V_1 , V_2 , V_3 , V_4 , NULL ) ;
}
#endif
if ( V_4 != NULL ) {
V_8 = 1 ;
V_1 -> V_4 = V_4 ;
} else
V_4 = V_1 -> V_4 ;
if ( V_2 != NULL ) {
V_8 = 1 ;
V_7 = F_8 ( V_4 ) ;
F_9 ( V_7 <= ( int ) sizeof( V_1 -> V_2 ) ) ;
if ( V_7 < V_3 ) {
if ( ! F_10 ( & V_1 -> V_18 , V_4 , V_5 ) )
goto V_19;
if ( ! F_11 ( & V_1 -> V_18 , V_2 , V_3 ) )
goto V_19;
if ( ! F_12 ( & ( V_1 -> V_18 ) , V_1 -> V_2 ,
& V_1 -> V_20 ) )
goto V_19;
} else {
F_9 ( V_3 >= 0 && V_3 <= ( int ) sizeof( V_1 -> V_2 ) ) ;
memcpy ( V_1 -> V_2 , V_2 , V_3 ) ;
V_1 -> V_20 = V_3 ;
}
if ( V_1 -> V_20 != V_10 )
memset ( & V_1 -> V_2 [ V_1 -> V_20 ] , 0 ,
V_10 - V_1 -> V_20 ) ;
}
if ( V_8 ) {
for ( V_6 = 0 ; V_6 < V_10 ; V_6 ++ )
V_9 [ V_6 ] = 0x36 ^ V_1 -> V_2 [ V_6 ] ;
if ( ! F_10 ( & V_1 -> V_12 , V_4 , V_5 ) )
goto V_19;
if ( ! F_11 ( & V_1 -> V_12 , V_9 , F_8 ( V_4 ) ) )
goto V_19;
for ( V_6 = 0 ; V_6 < V_10 ; V_6 ++ )
V_9 [ V_6 ] = 0x5c ^ V_1 -> V_2 [ V_6 ] ;
if ( ! F_10 ( & V_1 -> V_21 , V_4 , V_5 ) )
goto V_19;
if ( ! F_11 ( & V_1 -> V_21 , V_9 , F_8 ( V_4 ) ) )
goto V_19;
}
if ( ! F_13 ( & V_1 -> V_18 , & V_1 -> V_12 ) )
goto V_19;
return 1 ;
V_19:
return 0 ;
}
int F_14 ( T_1 * V_1 , const void * V_2 , int V_3 , const T_2 * V_4 )
{
if ( V_2 && V_4 )
F_15 ( V_1 ) ;
return F_1 ( V_1 , V_2 , V_3 , V_4 , NULL ) ;
}
int F_16 ( T_1 * V_1 , const unsigned char * V_22 , T_4 V_3 )
{
#ifdef F_2
if ( F_3 () && ! V_1 -> V_12 . V_13 )
return F_17 ( V_1 , V_22 , V_3 ) ;
#endif
return F_11 ( & V_1 -> V_18 , V_22 , V_3 ) ;
}
int F_18 ( T_1 * V_1 , unsigned char * V_4 , unsigned int * V_3 )
{
unsigned int V_6 ;
unsigned char V_23 [ V_24 ] ;
#ifdef F_2
if ( F_3 () && ! V_1 -> V_12 . V_13 )
return F_19 ( V_1 , V_4 , V_3 ) ;
#endif
if ( ! F_12 ( & V_1 -> V_18 , V_23 , & V_6 ) )
goto V_19;
if ( ! F_13 ( & V_1 -> V_18 , & V_1 -> V_21 ) )
goto V_19;
if ( ! F_11 ( & V_1 -> V_18 , V_23 , V_6 ) )
goto V_19;
if ( ! F_12 ( & V_1 -> V_18 , V_4 , V_3 ) )
goto V_19;
return 1 ;
V_19:
return 0 ;
}
void F_15 ( T_1 * V_1 )
{
F_20 ( & V_1 -> V_12 ) ;
F_20 ( & V_1 -> V_21 ) ;
F_20 ( & V_1 -> V_18 ) ;
}
int F_21 ( T_1 * V_25 , T_1 * V_26 )
{
if ( ! F_22 ( & V_25 -> V_12 , & V_26 -> V_12 ) )
goto V_19;
if ( ! F_22 ( & V_25 -> V_21 , & V_26 -> V_21 ) )
goto V_19;
if ( ! F_22 ( & V_25 -> V_18 , & V_26 -> V_18 ) )
goto V_19;
memcpy ( V_25 -> V_2 , V_26 -> V_2 , V_10 ) ;
V_25 -> V_20 = V_26 -> V_20 ;
V_25 -> V_4 = V_26 -> V_4 ;
return 1 ;
V_19:
return 0 ;
}
void F_23 ( T_1 * V_1 )
{
#ifdef F_2
if ( F_3 () && ! V_1 -> V_12 . V_13 ) {
F_24 ( V_1 ) ;
return;
}
#endif
F_25 ( & V_1 -> V_12 ) ;
F_25 ( & V_1 -> V_21 ) ;
F_25 ( & V_1 -> V_18 ) ;
memset ( V_1 , 0 , sizeof *V_1 ) ;
}
unsigned char * F_26 ( const T_2 * V_27 , const void * V_2 , int V_28 ,
const unsigned char * V_29 , T_4 V_30 , unsigned char * V_4 ,
unsigned int * V_31 )
{
T_1 V_32 ;
static unsigned char V_33 [ V_24 ] ;
if ( V_4 == NULL )
V_4 = V_33 ;
F_15 ( & V_32 ) ;
if ( ! F_14 ( & V_32 , V_2 , V_28 , V_27 ) )
goto V_19;
if ( ! F_16 ( & V_32 , V_29 , V_30 ) )
goto V_19;
if ( ! F_18 ( & V_32 , V_4 , V_31 ) )
goto V_19;
F_23 ( & V_32 ) ;
return V_4 ;
V_19:
return NULL ;
}
void F_27 ( T_1 * V_1 , unsigned long V_14 )
{
F_28 ( & V_1 -> V_12 , V_14 ) ;
F_28 ( & V_1 -> V_21 , V_14 ) ;
F_28 ( & V_1 -> V_18 , V_14 ) ;
}
