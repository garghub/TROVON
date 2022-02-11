int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int * V_4 )
{
int V_5 ;
if ( V_2 -> V_6 )
V_5 = F_2 ( V_2 -> V_6 , V_3 , V_4 ) ;
else if ( V_2 -> V_7 )
V_5 = V_2 -> V_7 ( V_2 , V_3 , V_4 ) ;
else
V_5 = - V_8 ;
return V_5 ;
}
int F_3 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
if ( V_2 -> V_6 )
return F_4 ( V_2 -> V_6 , V_3 , V_4 ) ;
else if ( V_2 -> V_9 )
return V_2 -> V_9 ( V_2 , V_3 , V_4 ) ;
else
return - V_8 ;
}
static int F_5 (
struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_10 , unsigned int V_4 , bool * V_11 )
{
unsigned int V_12 , V_13 ;
int V_5 ;
if ( ! V_2 -> V_7 || ! V_2 -> V_9 )
return - V_8 ;
F_6 ( & V_2 -> V_14 ) ;
V_5 = V_2 -> V_7 ( V_2 , V_3 , & V_12 ) ;
if ( V_5 < 0 )
goto V_15;
V_13 = ( V_12 & ~ V_10 ) | ( V_4 & V_10 ) ;
* V_11 = V_12 != V_13 ;
if ( * V_11 )
V_5 = V_2 -> V_9 ( V_2 , V_3 , V_13 ) ;
V_15:
F_7 ( & V_2 -> V_14 ) ;
return V_5 ;
}
int F_8 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_10 , unsigned int V_4 )
{
bool V_11 ;
int V_5 ;
if ( V_2 -> V_6 )
V_5 = F_9 ( V_2 -> V_6 , V_3 , V_10 ,
V_4 , & V_11 ) ;
else
V_5 = F_5 ( V_2 , V_3 ,
V_10 , V_4 , & V_11 ) ;
if ( V_5 < 0 )
return V_5 ;
return V_11 ;
}
int F_10 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_10 , unsigned int V_4 )
{
bool V_11 ;
int V_5 ;
if ( V_2 -> V_6 )
V_5 = F_11 ( V_2 -> V_6 , V_3 ,
V_10 , V_4 , & V_11 ) ;
else
V_5 = F_5 ( V_2 , V_3 ,
V_10 , V_4 , & V_11 ) ;
if ( V_5 < 0 )
return V_5 ;
return V_11 ;
}
void F_12 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 )
F_13 ( V_2 -> V_6 ) ;
}
int F_14 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_10 , unsigned int V_16 )
{
unsigned int V_12 , V_13 ;
int V_5 ;
V_5 = F_1 ( V_2 , V_3 , & V_12 ) ;
if ( V_5 < 0 )
return V_5 ;
V_13 = ( V_12 & ~ V_10 ) | V_16 ;
return V_12 != V_13 ;
}
unsigned int F_15 ( struct V_17 * V_18 , unsigned int V_3 )
{
unsigned int V_4 ;
int V_5 ;
V_5 = F_1 ( & V_18 -> V_2 , V_3 , & V_4 ) ;
if ( V_5 < 0 )
return - 1 ;
return V_4 ;
}
int F_16 ( struct V_17 * V_18 , unsigned int V_3 ,
unsigned int V_4 )
{
return F_3 ( & V_18 -> V_2 , V_3 , V_4 ) ;
}
int F_17 ( struct V_17 * V_18 , unsigned int V_3 ,
unsigned int V_10 , unsigned int V_16 )
{
return F_8 ( & V_18 -> V_2 , V_3 , V_10 ,
V_16 ) ;
}
int F_18 ( struct V_17 * V_18 , unsigned int V_3 ,
unsigned int V_10 , unsigned int V_16 )
{
return F_14 ( & V_18 -> V_2 , V_3 , V_10 , V_16 ) ;
}
int F_19 ( struct V_19 * V_20 ,
unsigned int V_3 )
{
unsigned int V_4 ;
int V_5 ;
V_5 = F_1 ( & V_20 -> V_2 , V_3 , & V_4 ) ;
if ( V_5 < 0 )
return - 1 ;
return V_4 ;
}
int F_20 ( struct V_19 * V_20 ,
unsigned int V_3 , unsigned int V_4 )
{
return F_3 ( & V_20 -> V_2 , V_3 , V_4 ) ;
}
